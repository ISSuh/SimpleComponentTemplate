/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADER_HPP_
#define SMT_LOADER_MODULELOADER_HPP_

#include <dlfcn.h>

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "smt/module/ModuleBase.hpp"
#include "smt/module/ModuleInfo.hpp"

namespace smt {
namespace loader {

// TODO(issuh) : Implement ModuleLoader Class
/**
 *  ModuleLoader Class
 *  
 *  Load user module class
 *  Interface for communicate user module
 * 
 **/
class ModuleLoader {
 public:
  ModuleLoader();
  ~ModuleLoader();

  template <typename Base>
  std::shared_ptr<Base> createModule(const std::string& className);

  void UnLoadModule();

 private:
  template<typename Base>
  void OnModuleObjDeleter(Base *obj);

 private:
  uint32_t m_loadedModuleCount;
  std::vector<std::shared_ptr<module::Module>> m_modules;
  std::map<std::string, module::ModuleInfo> m_moduleInfoMap;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADER_HPP_
