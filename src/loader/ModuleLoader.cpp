/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <dlfcn.h>

#include <string>
#include <algorithm>
#include <mutex>
#include <functional>

#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleLoaderUtil.hpp"

namespace smt {
namespace loader {

ModuleLoader::ModuleLoader() : m_loadedModuleCount(0) {}

ModuleLoader::~ModuleLoader() {}

template <typename Base>
std::shared_ptr<Base> ModuleLoader::createModule(const std::string& className) {
  // Base* moduleObject = smt::util::createModule<Base>(className);
  // if (moduleObject == nullptr) {
  //     // m_log->error("ModuleLoader::CreateClassObj failed {}", className);
  //     return std::shared_ptr<Base>();
  // }

  // // std::lock_guard<std::mutex> lock(m_loadedModuleCount_mutex);
  // ++m_loadedModuleCount;

  // std::shared_ptr<Base> moduleObject_shrPtr(
  //         moduleObject, std::bind(&ModuleLoader::OnModuleObjDeleter<Base>, this, std::placeholders::_1));

  // return moduleObject_shrPtr;
  return nullptr;
}

void ModuleLoader::UnLoadModule() {}

template<typename Base>
void ModuleLoader::OnModuleObjDeleter(Base *obj) {
  if (obj == nullptr) {
    return;
  }

  // std::lock_guard<std::mutex> lock(m_loadedModuleCount_mutex);
  delete obj;
  --m_loadedModuleCount;
}

}  // namespace loader
}  // namespace smt
