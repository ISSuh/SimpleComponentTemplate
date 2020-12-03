/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADERMANAGER_HPP_
#define SMT_LOADER_MODULELOADERMANAGER_HPP_

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "smt/module/Module.hpp"
#include "smt/loader/ModuleLoader.hpp"
#include "smt/util/JsonWrapper.hpp"

namespace smt {
namespace loader {

using LoaderId = uint64_t;

class ModuleLoadManager {
 public:
  ModuleLoadManager();
  ~ModuleLoadManager();

  void createModlueLoader(util::JsonWrapper specifications);

  void loadModule(LoaderId id, const module::ModuleInfo& moduleName);
  void loadAllModule();
  void unLoadModule(LoaderId id, const ModuleName& moduleName);
  void unLoadAllModule();

  std::shared_ptr<module::Module> getModule(const ModuleName& moduleName);
  bool hasModuleLoader(LoaderId id) const;
  bool hasModule(const ModuleName& modulName) const;

  LoaderId getLoaderIdByModuleName(const ModuleName& name) const { return m_loaderIdByModuleName.at(name); }

 private:
  void paraseModuleSpecifications(LoaderId id, util::JsonWrapper specification);

 private:
  std::map<LoaderId, std::unique_ptr<ModuleLoader<module::Module>>> m_loaderMap;
  std::map<LoaderId, ModuleInfomations> m_moduleInfomationsByLoader;
  std::map<ModuleName, LoaderId> m_loaderIdByModuleName;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERMANAGER_HPP_
