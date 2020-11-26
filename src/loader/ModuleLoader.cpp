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

void ModuleLoader::unLoadModule(const std::string& className) {
  std::cout << "ModuleLoader::UnLoadModule - " << className << std::endl;
  if (m_modules.find(className) != m_modules.end()) {
    m_modules[className].reset();
    m_modules.erase(className);
    --m_loadedModuleCount;
  }
}

}  // namespace loader
}  // namespace smt
