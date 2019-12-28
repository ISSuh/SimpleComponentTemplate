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

#ifndef SMT_CONTROLLER_MODUL_CONTROLLER
#define SMT_CONTROLLER_MODUL_CONTROLLER

#include <vector>
#include <memory>

#include <smt/module/module_base.hpp>
#include <smt/loader/module_load_manager.hpp>

namespace smt {

namespace controller {

using json = nlohmann::json;

// TODO : Implement ModuleController Class
/**
 *  ModuleController Class
 * 
 **/
class ModuleController {
public:
    explicit ModuleController() : m_handle(smt::base::Handle::GetInstence()), m_log(spdlog::get(m_handle->GetNodeName())) {}
    
    bool Init() {
        if(!LoadAllModule()){
            m_log->error("Fail Load Module");
            return false;
        }

        return true;
    }

    void Clear() {}

private:
    bool LoadAllModule() {
        auto args = m_handle->GetArguments();

        for(const auto& moduleIndex : args){
            if(!LoadMoule(m_handle->GetArguments_map(moduleIndex.first))){
                m_log->error("Fail Load {} Module", moduleIndex.first);
                return false;
            }
        }
        return true;
    }

    bool LoadMoule(const json& arg) {
        auto moduleName = arg[JSONKEY_MODULE_NAME].get<std::string>();
        auto className = arg[JSONKEY_MODULE][JSONKEY_CLASS_NAME].get<std::string>();

        m_loadManager.LoadModule(moduleName);

        std::shared_ptr<ModuleBase> base = m_loadManager.CreateClassObj<ModuleBase>(moduleName, className);

        component_list_.emplace_back(std::move(base));
    
        return true;
    }

private:
    smt::base::Handle *m_handle;
    std::shared_ptr<spdlog::logger> m_log;

    smt::loader::ModuleLoadManager m_loadManager;
    std::vector<std::shared_ptr<smt::module::ModuleBase>> m_moduleLists;
};

} // controller

} // smt

#endif