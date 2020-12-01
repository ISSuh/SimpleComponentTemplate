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

#include "smt/module/Module.hpp"
#include "smt/module/ModuleInfo.hpp"

namespace smt {
namespace loader {

using ModuleName = std::string;
using ModuleClassName = std::string;
using ModuleInfomations = std::vector<module::ModuleInfo>;

// TODO(issuh) : Implement ModuleLoader Class
class ModuleLoader {
 public:
  explicit ModuleLoader(const ModuleInfomations& moduleInfomations);
  ~ModuleLoader();

  ModuleLoader() = delete;

  void loadModule(const ModuleName& moduleName);
  void loadAllModule();

  void unLoadModule(const ModuleName& moduleName);
  void unLoadAllModule();

  template <typename Base>
  std::shared_ptr<Base> createModuleObject(const ModuleName& moduleName);

  void distroyModuleObject(const ModuleName& moduleName);

  // template <typename Base>
  // std::shared_ptr<Base> createAllModuleObject();

 private:
  uint32_t m_loadedModuleCount;
  uint32_t m_moduleObjectCount;

  std::map<ModuleClassName, std::unique_ptr<loader::AbstractModlueFactory<module::Module>>> m_moduleFactoryMap;
  std::map<ModuleName, std::shared_ptr<module::Module>> m_moduleObjectMap;
  std::map<ModuleName, module::ModuleInfo> m_moduleInfoMap;
};

template <typename Base>
std::shared_ptr<Base> ModuleLoader::createModuleObject(const std::string& moduleName) {
  std::cout << "ModuleLoader::createModuleObject - " << moduleName << std::endl;

  ModuleClassName className = m_moduleInfoMap[moduleName].getClassName();

  if (ModuleLoaderUtil::searchModuleFactorybyClassNeme(className) == false) {
    return nullptr;
  }

  // const smt::loader::AbstractModlueFactory<Base>* facotry =
  //         ModuleLoaderUtil::getModuleFactory<Base>(className);

  // std::lock_guard<std::mutex> lock(m_loadedModuleCount_mutex);
  m_moduleObjectMap[moduleName] = std::shared_ptr<Base>(m_moduleFactoryMap[className]->createModule());
  ++m_moduleObjectCount;

  return m_moduleObjectMap[moduleName];
}

// template <typename Base>
// std::vector<std::shared_ptr<Base>> ModuleLoader::createAllModuleObject() {
//   for (const auto& info : m_moduleInfoMap) {

//   }
// }

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADER_HPP_
