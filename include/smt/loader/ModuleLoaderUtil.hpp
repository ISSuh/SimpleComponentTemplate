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

#ifndef SMT_LOADER_MODULELOADERUTIL_HPP_   
#define SMT_LOADER_MODULELOADERUTIL_HPP_

#include <iostream>
#include <vector>
#include <map>
#include <mutex>
#include <memory>

#include "smt/module/ModuleBase.hpp"
#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleFactory.hpp"

namespace smt {

namespace loader {

class ModuleLoader;

namespace util{

using UserModuleFactoryMap = std::map<std::string, smt::loader::AbstractModuleFactoryBase*>;
using ModuleNamebyFactoryMap = std::map<std::string, smt::loader::AbstractModuleFactoryBase*>;
using UserModuleClassMap = std::map<std::string, smt::module::ModuleBase*>;

std::recursive_mutex& GetModuleFactorMapMutex() {
  static std::recursive_mutex instance;
  return instance;
}

std::recursive_mutex& GetModuleNamebyFactoryMapMutex() {
  static std::recursive_mutex instance;
  return instance;
}

UserModuleFactoryMap& GetUserModulFactoryMap(){
    static UserModuleFactoryMap instance;
    return instance;
}

UserModuleClassMap& GetUserModuleClassMap(){
    static UserModuleClassMap instance;
    return instance;
}

template<typename ModuleClass, typename Base>
void RegistClass(const std::string& className, const std::string& baseCalssName){
    AbstractModlueFactory<Base>* moduleFactrory_obj =
      new ModuleFactory<ModuleClass, Base>(className, baseCalssName);

    std::cout << "RegistClass" << std::endl;

    // GetModuleFactorMapMutex.lock();
    auto& factoryMap = GetUserModulFactoryMap();
    factoryMap[className] = moduleFactrory_obj;
    // GetModuleFactorMapMutex.unlock();
}


template <typename Base>
Base* CreateUserClassObj(const std::string& className) {
    auto& factoryMap = GetUserModulFactoryMap();

    AbstractModlueFactory<Base>* factory = nullptr;
    if (factoryMap.find(className) != factoryMap.end()) {
        // factory = dynamic_cast<AbstractModlueFactory<Base>* >(factoryMap[className]);
        factory = (AbstractModlueFactory<Base>*)(factoryMap[className]);
    }

    Base* classObj = nullptr;
    if(factory){
        classObj = factory->CreateObj();
    } 

    return classObj;
}

}  // namespace util
}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERUTIL_HPP_
