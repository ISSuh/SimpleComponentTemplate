/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULELOADER_HPP_
#define SMT_LOADER_MODULELOADER_HPP_

#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <mutex>
#include <functional>

#include "smt/module/ModuleBase.hpp"
#include "smt/loader/ModuleLoader_util.hpp"

namespace smt {
namespace loader {

// TODO(issuh) : Implement ComponentController Class
/**
 *  ComponentController Class
 *  
 *  Init user components class
 *  Load all user components class
 *  Add user components class
 *  Clear user components class 
 *  scheduling user components class 
 * 
 **/
class ModuleLoader {
 public:
  ModuleLoader() : m_handle(smt::base::Handle::GetInstence()),
                   m_log(spdlog::get(m_handle->GetNodeName())) {}

  void LoadModule() {}

  template <typename Base>
  std::shared_ptr<Base> CreateClassObj(const std::string& className) {
    Base* moduleObject = util::CreateUserClassObj<Base>(className);
    if (moduleObject == nullptr) {
        m_log->error("ModuleLoader::CreateClassObj failed {}", className);
        return std::shared_ptr<Base>();
    }

    std::lock_guard<std::mutex> lock(m_loadedModule_count_mutex);
    ++m_loadedModule_count;

    std::shared_ptr<Base> moduleObject_shrPtr(
            moduleObject, std::bind(&ModuleLoader::OnModuleObjDeleter<Base>, this, std::placeholders::_1));

    return moduleObject_shrPtr;
  }

  void UnLoadModule() {}

 private:
  template<typename Base>
  void OnModuleObjDeleter(Base *obj) {
    if (obj == nullptr) {
      return;
    }

    std::lock_guard<std::mutex> lock(m_loadedModule_count_mutex);
    delete obj;
    --m_loadedModule_count;
  }

 private:
  smt::base::Handle* m_handle;
  std::shared_ptr<spdlog::logger> m_log;

  std::mutex m_loadedModule_count_mutex;

  int m_loadedModule_count = 0;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULELOADER_HPP_
