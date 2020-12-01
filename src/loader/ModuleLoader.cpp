/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <algorithm>
#include <mutex>
#include <functional>

#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleLoaderUtil.hpp"
#include "smt/loader/ModuleOpener.hpp"

namespace smt {
namespace loader {

ModuleLoader::ModuleLoader(const ModuleInfomations& moduleInfomations)
  : m_loadedModuleCount(0),
    m_moduleObjectCount(0) {
  for (const module::ModuleInfo& info : moduleInfomations) {
    m_moduleInfoMap.insert({info.getBaseModuleName(), info});
  }
}

ModuleLoader::~ModuleLoader() {}

void ModuleLoader::loadModule(const ModuleName& moduleName) {
  const std::string modulePath = m_moduleInfoMap[moduleName].getModulePath();
  smt::loader::ModuleOpener::moduleOpen(modulePath);

  ModuleClassName className = m_moduleInfoMap[moduleName].getClassName();

  std::unique_ptr<loader::AbstractModlueFactory<module::Module>>
    factory(ModuleLoaderUtil::getModuleFactory<module::Module>(className));

  m_moduleFactoryMap.insert({moduleName, 
                            });

  // m_moduleFactoryMap[moduleName].reset(ModuleLoaderUtil::getModuleFactory<module::Module>(className));

  ++m_loadedModuleCount;
}

void ModuleLoader::loadAllModule() {
  std::cout << "ModuleLoader::loadAllModule" << std::endl;

  for (const auto& info : m_moduleInfoMap) {
    loadModule(info.first);
  }
}

void ModuleLoader::unLoadModule(const ModuleName& moduleName) {
  std::cout << "ModuleLoader::UnLoadModule - " << moduleName << std::endl;

  m_moduleObjectMap[moduleName].reset();
  m_moduleObjectMap.erase(moduleName);
  --m_loadedModuleCount;
}

void ModuleLoader::unLoadAllModule() {
  std::cout << "ModuleLoader::unLoadAllModule" << std::endl;

  for (const auto& info : m_moduleInfoMap) {
    unLoadModule(info.first);
  }
}

void ModuleLoader::distroyModuleObject(const ModuleName& moduleName) {
  std::cout << "ModuleLoader::distroyModuleObject - " << moduleName << std::endl;

  if (m_moduleObjectMap.find(moduleName) != m_moduleObjectMap.end()) {
    m_moduleObjectMap[moduleName].reset();
    m_moduleObjectMap.erase(moduleName);
    --m_moduleObjectCount;
  }
}

}  // namespace loader
}  // namespace smt
