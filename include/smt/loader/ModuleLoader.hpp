/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADER_HPP_
#define SMT_LOADER_MODULELOADER_HPP_

#include <dlfcn.h>

#include <string>
#include <map>
#include <memory>

#include "smt/module/Module.hpp"
#include "smt/module/ModuleInfo.hpp"

namespace smt {
namespace loader {

// TODO(issuh) : Implement ModuleLoader Class
class ModuleLoader {
 public:
  ModuleLoader();
  ~ModuleLoader();

  template <typename Base>
  std::shared_ptr<Base> createModule(const std::string& className);
  void unLoadModule(const std::string& className);

 private:
  uint32_t m_loadedModuleCount;
  std::map<std::string, std::shared_ptr<smt::module::Module>> m_modules;
  std::map<std::string, smt::module::UserModuleInfo> m_moduleInfoMap;
};

template <typename Base>
std::shared_ptr<Base> ModuleLoader::createModule(const std::string& className) {
  std::cout << "ModuleLoader::createModule - " << className << std::endl;

  if (ModuleLoaderUtil::searchModulebyClassNeme(className) == false) {
    return nullptr;
  }

  const smt::loader::AbstractModlueFactory<Base>* facotry =
          ModuleLoaderUtil::getModuleFactory<Base>(className);

  // std::lock_guard<std::mutex> lock(m_loadedModuleCount_mutex);

  m_modules[className] = std::shared_ptr<Base>(facotry->createModule());
  ++m_loadedModuleCount;

  return m_modules[className];
}

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADER_HPP_
