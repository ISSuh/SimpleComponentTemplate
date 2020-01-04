/******************************************************************************
 * Copyright 2019 The ISSuh Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef SMT_LOADER_MODUL_LOAD_MANAGER
#define SMT_LOADER_MODUL_LOAD_MANAGER

#include <map>
#include <memory>

#include <smt/base/handle.hpp>
#include <smt/loader/module_loader.hpp>

namespace smt {

namespace loader {

// TODO : Implement ModuleLoaderManager Class
/**
 *  ModuleLoaderManager Class
 *  
 * 
 **/
class ModuleLoadManager {
public:
    explicit ModuleLoadManager() : m_handle(smt::base::Handle::GetInstence()), m_log(spdlog::get(m_handle->GetNodeName())) {}

    void LoadModule(const std::string& moduleName) {
        m_loader_map[moduleName] = new smt::loader::ModuleLoader();
    }
    
    template <typename Base>
    std::shared_ptr<Base> CreateClassObj(const std::string& moduleName, const std::string& className) {
        ModuleLoader* loader = GetModuleLoader(moduleName);
        if(!loader){
            m_log->error("ModuleLoadManager::Could not create user class obj {}", className);
            return std::shared_ptr<Base>();
        }

        return loader->CreateClassObj<Base>(className);
    }

    void UnLoadModule() {}

private:
    ModuleLoader* GetModuleLoader(const std::string& moduleName) {
        return m_loader_map[moduleName];
    }
    
private:
    smt::base::Handle* m_handle;
    std::shared_ptr<spdlog::logger> m_log;

    std::map<std::string, smt::loader::ModuleLoader*> m_loader_map;
};

} // loader

} // smt

#endif