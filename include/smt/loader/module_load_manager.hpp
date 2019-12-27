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

#ifndef SMT_CONTROLLER_MODUL_LOAD_MANAGER
#define SMT_CONTROLLER_MODUL_LOAD_MANAGER

#include <map>
#include <memory>

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
    void LoadModule() {}

    template <typename ModuleClass>
    std::shared_ptr<ModuleClass> CreateClassObj() {}

    void UnLoadModule() {}

private:

private:
    std::map<std::string, std::unique_ptr<smt::loader::ModuleLoader>> m_loader_map;
};

} // loader

} // smt

#endif