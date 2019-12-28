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

#ifndef SMT_CONTROLLER_MODUL_LOADER
#define SMT_CONTROLLER_MODUL_LOADER

#include <vector>
#include <memory>
#include <mutex>

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
    
    template <typename ModuleClass>
    std::shared_ptr<ModuleClass> CreateClassObj(const std::string& className) {
        Base* moduleObject;
        if (class_object == nullptr) {
            m_log->error("CreateClassObj failed {}", className);
            return std::shared_ptr<Base>();
        }

        std::lock_guard<std::mutex> lock(classobj_ref_count_mutex_);
        ++m_loadedModule_count;
    }

    void UnLoadModule() {}

private:
    smt::base::Handle* m_handle;
    std::shared_ptr<spdlog::logger> m_log;

    std::mutex m_loadedModule_count_mutex;

    int m_loadedModule_count = 0;
};

} // loader

} // smt

#endif