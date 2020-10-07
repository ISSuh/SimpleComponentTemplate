/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADERUTIL_HPP_
#define SMT_LOADER_MODULELOADERUTIL_HPP_

#include <string>
#include <map>

#include "smt/loader/ModuleFactory.hpp"

namespace smt {
namespace loader {

// using UserModuleFactoryMap = std::map<std::string, smt::loader::AbstractModuleFactoryBase*>;

// std::recursive_mutex& getModuleFactorMapMutex() {
//   static std::recursive_mutex instance;
//   return instance;
// }

// std::recursive_mutex& getModuleNamebyFactoryMapMutex() {
//   static std::recursive_mutex instance;
//   return instance;
// }

// UserModuleFactoryMap& getUserModulFactoryMap() {
//   static UserModuleFactoryMap instance;
//   return instance;
// }

// template<typename UserModule, typename BaseModule>
// void registUserModule(const std::string& className, const std::string& baseCalssName) {
//   AbstractModlueFactory<BaseModule>* moduleFactrory =
//     new ModuleFactory<UserModule, BaseModule>(className, baseCalssName);

//   std::cout << "RegistClass" << std::endl;

//   // getModuleFactorMapMutex.lock();
//   auto& factoryMap = getUserModulFactoryMap();
//   factoryMap[className] = moduleFactrory;
//   // getModuleFactorMapMutex.unlock();
// }


// template <typename BaseModule>
// std::shared_ptr<BaseModule> createUserModule(const std::string& className) {
//   auto& factoryMap = getUserModulFactoryMap();

//   AbstractModlueFactory<BaseModule>* factory = nullptr;
//   if (factoryMap.find(className) != factoryMap.end()) {
//       // factory = dynamic_cast<AbstractModlueFactory<Base>* >(factoryMap[className]);
//       factory = (AbstractModlueFactory<BaseModule>*)(factoryMap[className]);
//   }

//   std::shared_ptr<BaseModule> userModule;
//   if (factory) {
//       userModule = factory->createModule();
//   }

//   return classObj;
// }

using UserModuleFactoryMap = std::map<std::string, smt::loader::AbstractModuleFactoryBase*>;

class ModuleLoaderUtil {
 public:

  template<typename UserModule, typename BaseModule>
  static void registUserModule(const std::string& className, const std::string& baseCalssName);

  template <typename BaseModule>
  static std::shared_ptr<BaseModule> createUserModule(const std::string& className);

 private:
  static UserModuleFactoryMap m_factoryMap;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERUTIL_HPP_
