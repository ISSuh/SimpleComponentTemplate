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

#ifndef SMT_LOADER_MODUL_LOADER
#define SMT_LOADER_MODUL_LOADER

#include <vector>
#include <algorithm>
#include <memory>
#include <mutex>
#include <functional>

#include <smt/module/module_base.hpp>
#include <smt/loader/module_loader_util.hpp>

namespace smt {

namespace loader {

// TODO : Implement ComponentController Class
/**
 *  ComponentController Class
 *  
 *  Init user components class
 *  Load all user components class
 *  Add user components class
 *  Clear user components class 
 *  scheduling user components class 
 * 
 **/
class ModuleLoader {
public:
    explicit ModuleLoader() : m_handle(smt::base::Handle::GetInstence()), m_log(spdlog::get(m_handle->GetNodeName())) {}

    void LoadModule() {}
    
    template <typename Base>
    std::shared_ptr<Base> CreateClassObj(const std::string& className) {
        Base* moduleObject = util::CreateUserClassObj<Base>(className);
        if (moduleObject == nullptr) {
            m_log->error("ModuleLoader::CreateClassObj failed {}", className);
            return std::shared_ptr<Base>();
        }

        std::lock_guard<std::mutex> lock(m_loadedModule_count_mutex);
        ++m_loadedModule_count;

        std::shared_ptr<Base> moduleObject_shrPtr(moduleObject, std::bind(&ModuleLoader::OnModuleObjDeleter<Base>, this, std::placeholders::_1));

        return moduleObject_shrPtr;
    }

    void UnLoadModule() {}

private:
    template<typename Base>
    void OnModuleObjDeleter(Base *obj) {
        if(obj == nullptr){
            return;
        }
        
        std::lock_guard<std::mutex> lock(m_loadedModule_count_mutex);
        delete obj;
        --m_loadedModule_count;
    }

private:
    smt::base::Handle* m_handle;
    std::shared_ptr<spdlog::logger> m_log;

    std::mutex m_loadedModule_count_mutex;

    int m_loadedModule_count = 0;
};

} // loader

} // smt

#endif