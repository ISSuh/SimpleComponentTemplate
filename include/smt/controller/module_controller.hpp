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
#include <smt/loader/module_loader.hpp>


namespace smt {

namespace controller {

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
class ModuleController {
public:
    bool Init() {};
    void Clear() {};

private:
    bool LoadAllModule() {};

    bool LoadMoule() {};

private:
    smt::loader::ModuleLoader m_loader;
    std::vector<std::shared_ptr<smt::module::ModuleBase>> m_moduleLists;
};

} // controller

} // smt

#endif