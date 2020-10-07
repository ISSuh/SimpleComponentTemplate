/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <mutex>
#include <memory>

#include "smt/loader/ModuleLoaderUtil.hpp"

namespace smt {
namespace loader {

UserModuleFactoryMap ModuleLoaderUtil::m_factoryMap = UserModuleFactoryMap();

template<typename UserModule, typename BaseModule>
static void registUserModule(const std::string& className, const std::string& baseCalssName) {
  AbstractModlueFactory<BaseModule>* moduleFactrory =
      new ModuleFactory<UserModule, BaseModule>(className, baseCalssName);

  std::cout << "RegistClass" << std::endl;

  // getModuleFactorMapMutex.lock();
  // auto& factoryMap = getUserModulFactoryMap();
  // factoryMap[className] = moduleFactrory;
  // getModuleFactorMapMutex.unlock();
}

template <typename BaseModule>
static std::shared_ptr<BaseModule> createUserModule(const std::string& className) {
  // auto& factoryMap = getUserModulFactoryMap();

  // AbstractModlueFactory<BaseModule>* factory = nullptr;
  // if (factoryMap.find(className) != factoryMap.end()) {
      // factory = dynamic_cast<AbstractModlueFactory<Base>* >(factoryMap[className]);
  //     factory = (AbstractModlueFactory<BaseModule>*)(factoryMap[className]);
  // }

  // std::shared_ptr<BaseModule> userModule;
  // if (factory) {
  //     userModule = factory->createModule();
  // }

  // return userModule;

  return nullptr;
}

}  // namespace loader
}  // namespace smt
