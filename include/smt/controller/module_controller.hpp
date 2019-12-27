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

// TODO : Implement ModuleController Class
/**
 *  ModuleController Class
 * 
 **/
class ModuleController {
public:
    explicit ModuleController(smt::base::Handle &handle) : m_handle(handle) {
        m_log = spdlog::get(m_handle.GetNodeName());
    }
    
    bool Init() {
        if(!LoadAllModule()){
            
            return false;
        }

        return true;
    }

    void Clear() {}

private:
    bool LoadAllModule() {
        return false;
    }

    bool LoadMoule() {
        return false;
    }

private:
    std::shared_ptr<spdlog::logger> m_log;
    smt::base::Handle &m_handle;

    smt::loader::ModuleLoadManager m_loadManager;
    std::vector<std::shared_ptr<smt::module::ModuleBase>> m_moduleLists;
};

} // controller

} // smt

#endif