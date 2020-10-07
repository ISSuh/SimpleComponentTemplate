/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <map>
#include <memory>

#include "smt/loader/ModuleLoaderManager.hpp"

namespace smt {
namespace loader {

ModuleLoadManager::ModuleLoadManager() {}

ModuleLoadManager::~ModuleLoadManager() {}

void ModuleLoadManager::LoadModule(const std::string& moduleName) {
    m_loaderMap[moduleName] = std::unique_ptr<ModuleLoader>(new smt::loader::ModuleLoader());
}

void ModuleLoadManager::UnLoadModule() {}

template <typename Base>
std::shared_ptr<Base> ModuleLoadManager::CreateClassObj(const std::string& moduleName, const std::string& className) {
  ModuleLoader* loader = GetModuleLoader(moduleName);
  if (!loader) {
    // m_log->error("ModuleLoadManager::Could not create user class obj {}", className);
    return std::shared_ptr<Base>();
  }

  return loader->CreateClassObj<Base>(className);
}


ModuleLoader* ModuleLoadManager::GetModuleLoader(const std::string& moduleName) {
  return m_loaderMap[moduleName].get();
}

}  // namespace loader
}  // namespace smt
