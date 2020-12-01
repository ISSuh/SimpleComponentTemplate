/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADERUTIL_HPP_
#define SMT_LOADER_MODULELOADERUTIL_HPP_

#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <utility>

#include "smt/loader/ModuleFactory.hpp"

namespace smt {
namespace loader {

using ModuleFactoryMap = std::map<std::string, loader::AbstractModuleFactoryBase*>;

class ModuleLoaderUtil {
 public:
  template<typename UserModule, typename BaseModule>
  static void registUserModule(const std::string& className, const std::string& baseCalssName);

  template <typename BaseModule>
  static const loader::AbstractModlueFactory<BaseModule>* getModuleFactory(const std::string& className);

  static bool searchModuleFactorybyClassNeme(const std::string& className);

  static void releaseModuleFactory(const std::string& className);

 private:
  static ModuleFactoryMap m_factoryMap;
};

template<typename UserModule, typename BaseModule>
void ModuleLoaderUtil::registUserModule(const std::string& className,
                                        const std::string& baseCalssName) {
  std::cout << "ModuleLoaderUtil::RegistClass - " << className << ", " << baseCalssName << std::endl;

  AbstractModlueFactory<BaseModule>* moduleFactrory =
      new ModuleFactory<UserModule, BaseModule>(className, baseCalssName);

  m_factoryMap[className] = moduleFactrory;
}

template <typename BaseModule>
const smt::loader::AbstractModlueFactory<BaseModule>* ModuleLoaderUtil::getModuleFactory(const std::string& className) {
  if (ModuleLoaderUtil::searchModuleFactorybyClassNeme(className) == false) {
    return nullptr;
  }
  return dynamic_cast<AbstractModlueFactory<BaseModule>*>(m_factoryMap[className]);
}

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERUTIL_HPP_
