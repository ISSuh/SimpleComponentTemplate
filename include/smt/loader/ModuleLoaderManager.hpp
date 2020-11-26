/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADERMANAGER_HPP_
#define SMT_LOADER_MODULELOADERMANAGER_HPP_

#include <string>
#include <map>
#include <memory>

#include "smt/loader/ModuleLoader.hpp"

namespace smt {
namespace loader {

class ModuleLoadManager {
 public:
  ModuleLoadManager();
  ~ModuleLoadManager();

  void LoadModule(const std::string& moduleName);
  void UnLoadModule();

  template <typename Base>
  std::shared_ptr<Base> CreateClassObj(const std::string& moduleName, const std::string& className);

 private:
  ModuleLoader* GetModuleLoader(const std::string& moduleName);

 private:
  std::map<std::string, std::unique_ptr<ModuleLoader>> m_loaderMap;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADERMANAGER_HPP_
