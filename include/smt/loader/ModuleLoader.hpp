/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADER_HPP_
#define SMT_LOADER_MODULELOADER_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <utility>

#include "smt/module/ModuleInfo.hpp"
#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleLoaderUtil.hpp"
#include "smt/loader/ModuleOpener.hpp"
#include "smt/loader/ModuleFactory.hpp"

namespace smt {
namespace loader {

using ModuleName = std::string;
using ModuleClassName = std::string;
using ModulePath = std::string;
using ModuleInfomations = std::vector<module::ModuleInfo>;

template <typename Base>
class ModuleLoader {
 public:
  ModuleLoader() = default;
  ~ModuleLoader() = default;

  void loadModule(const module::ModuleInfo& info);
  void unLoadModule(const ModuleName& moduleName);

  std::shared_ptr<Base> getModule(const ModuleName& moduleName) const;
  bool hasModule(const ModuleName& moduleName) const;

 private:
  std::shared_ptr<Base> createModuleObject(const ModuleClassName& moduleName);
  void distroyModuleObject(const ModuleName& moduleName);

 private:
  std::map<ModuleName, module::ModuleInfo> m_moduleInfomationsMap;
  std::map<ModuleName, std::shared_ptr<Base>> m_moduleObjectMap;
};

template <typename Base>
void ModuleLoader<Base>::loadModule(const module::ModuleInfo& info) {
  const ModuleName moduleName = info.getModuleName();
  const ModulePath modulePath = info.getModulePath();
  const ModuleClassName moduleClassName = info.getClassName();

  m_moduleInfomationsMap[moduleName] = info;

  smt::loader::ModuleOpener::moduleOpen(modulePath);

  m_moduleObjectMap[modulePath] = std::move(createModuleObject(moduleClassName));
}

template <typename Base>
void ModuleLoader<Base>::unLoadModule(const ModuleName& moduleName) {
  std::cout << "ModuleLoader::UnLoadModule - " << moduleName << std::endl;

  distroyModuleObject(moduleName);
}

template <typename Base>
std::shared_ptr<Base> ModuleLoader<Base>::getModule(const ModuleName& moduleName) const {
  if (!hasModule(moduleName)) {
    return nullptr;
  }
  return m_moduleObjectMap.at(moduleName);
}

template <typename Base>
bool ModuleLoader<Base>::hasModule(const ModuleName& moduleName) const {
  if (m_moduleObjectMap.find(moduleName) != m_moduleObjectMap.end()) {
    return true;
  }
  return false;
}

template <typename Base>
std::shared_ptr<Base> ModuleLoader<Base>::createModuleObject(const ModuleClassName& moduleClassName) {
  std::cout << "ModuleLoader::createModuleObject - " << moduleClassName << std::endl;

  if (ModuleLoaderUtil::searchModuleFactorybyClassNeme(moduleClassName) == false) {
    std::cout << "ModuleLoader::createModuleObject - " << moduleClassName << " load fail" << std::endl;
    return nullptr;
  }

  const loader::AbstractModlueFactory<Base>* factory(ModuleLoaderUtil::getModuleFactory<Base>(moduleClassName));

  // std::lock_guard<std::mutex> lock(m_loadedModuleCount_mutex);
  std::shared_ptr<Base> moduleObject = std::shared_ptr<Base>(factory->createModule());

  return std::move(moduleObject);
}

template <typename Base>
void ModuleLoader<Base>::distroyModuleObject(const ModuleName& moduleName) {
  std::cout << "ModuleLoader::distroyModuleObject - " << moduleName << std::endl;

  if (hasModule(moduleName)) {
    m_moduleObjectMap[moduleName].reset();
    m_moduleObjectMap.erase(moduleName);
  }
}

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADER_HPP_
