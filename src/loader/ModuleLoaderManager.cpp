/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>

#include "smt/loader/ModuleLoaderManager.hpp"
#include "smt/util/IdGenerator.hpp"

namespace smt {
namespace loader {

ModuleLoadManager::ModuleLoadManager() {}

ModuleLoadManager::~ModuleLoadManager() {}

void ModuleLoadManager::createModlueLoader(util::JsonWrapper specifications) {
  std::cout << "ModuleLoadManager::createModlueLoader";

  LoaderId id = util::idGenerator();
  paraseModuleSpecifications(id, specifications);

  m_loaderMap[id] = std::unique_ptr<ModuleLoader<module::Module>>(new ModuleLoader<module::Module>());
}

void ModuleLoadManager::loadModule(LoaderId id, const module::ModuleInfo& info) {
  m_loaderMap[id]->loadModule(info);
}

void ModuleLoadManager::loadAllModule() {
  for (const auto& moduleInfoByid : m_moduleInfomationsByLoader) {
    LoaderId id = moduleInfoByid.first;
    for (const module::ModuleInfo moduleInfo : moduleInfoByid.second) {
      loadModule(id, moduleInfo);
    }
  }
}

void ModuleLoadManager::unLoadModule(LoaderId id, const ModuleName& moduleName) {
  m_loaderMap[id]->unLoadModule(moduleName);
}

void ModuleLoadManager::unLoadAllModule() {
  for (const auto& moduleInfoByid : m_moduleInfomationsByLoader) {
    LoaderId id = moduleInfoByid.first;
    for (const module::ModuleInfo moduleInfo : moduleInfoByid.second) {
      ModuleName name = moduleInfo.getModuleName();
      unLoadModule(id, name);
    }
  }
}

std::shared_ptr<module::Module> ModuleLoadManager::getModule(const ModuleName& moduleName) {
  LoaderId id = m_loaderIdByModuleName[moduleName];
  return std::move(m_loaderMap[id]->getModule(moduleName));
}

bool ModuleLoadManager::hasModuleLoader(LoaderId id) const {
  if (m_loaderMap.find(id) != m_loaderMap.end()) {
    return true;
  }
  return false;
}

bool ModuleLoadManager::hasModule(const ModuleName& modulName) const {
  if (m_loaderIdByModuleName.find(modulName) == m_loaderIdByModuleName.end()) {
    return false;
  }

  LoaderId id = m_loaderIdByModuleName.at(modulName);
  if (m_loaderMap.at(id)->hasModule(modulName)) {
    return true;
  }

  return false;
}


void ModuleLoadManager::paraseModuleSpecifications(LoaderId id, util::JsonWrapper specifications) {
  ModuleInfomations infomations;
  util::JsonWrapper modules(specifications[util::JSONKEY::MODULE]);
  for (uint32_t i = 0 ; i < modules.size() ; ++i) {
    module::ModuleInfo info;
    info.parseModueInfoOnJson(modules[i]);

    ModuleName name = info.getModuleName();
    m_loaderIdByModuleName[name] = id;

    infomations.emplace_back(info);
  }

  m_moduleInfomationsByLoader[id] = std::move(infomations);
}

}  // namespace loader
}  // namespace smt
