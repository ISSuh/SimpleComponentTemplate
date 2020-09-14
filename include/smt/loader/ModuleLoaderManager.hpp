/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULE_LOAD_MANAGER_HPP_
#define SMT_LOADER_MODULE_LOAD_MANAGER_HPP_

#include <map>
#include <memory>

#include "smt/base/handle.hpp"
#include "smt/loader/ModuleLoader.hpp"

namespace smt {
namespace loader {

// TODO(issuh) : Implement ModuleLoaderManager Class
/**
 *  ModuleLoaderManager Class
 *  
 * 
 **/
class ModuleLoadManager {
 public:
  ModuleLoadManager() : m_handle(smt::base::Handle::GetInstence()),
                        m_log(spdlog::get(m_handle->GetNodeName())) {}

  void LoadModule(const std::string& moduleName) {
      m_loader_map[moduleName] = new smt::loader::ModuleLoader();
  }

  template <typename Base>
  std::shared_ptr<Base> CreateClassObj(const std::string& moduleName, const std::string& className) {
    ModuleLoader* loader = GetModuleLoader(moduleName);
    if (!loader) {
      m_log->error("ModuleLoadManager::Could not create user class obj {}", className);
      return std::shared_ptr<Base>();
    }

    return loader->CreateClassObj<Base>(className);
  }

  void UnLoadModule() {}

 private:
  ModuleLoader* GetModuleLoader(const std::string& moduleName) {
    return m_loader_map[moduleName];
  }

 private:
  smt::base::Handle* m_handle;
  std::shared_ptr<spdlog::logger> m_log;

  std::map<std::string, smt::loader::ModuleLoader*> m_loader_map;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULE_LOAD_MANAGER_HPP_