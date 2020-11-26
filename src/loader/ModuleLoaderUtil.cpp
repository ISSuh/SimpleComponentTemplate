/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include "smt/loader/ModuleLoaderUtil.hpp"

namespace smt {
namespace loader {

ModuleFactoryMap ModuleLoaderUtil::m_factoryMap = ModuleFactoryMap();

bool ModuleLoaderUtil::searchModulebyClassNeme(const std::string& className) {
  if (m_factoryMap.find(className) == m_factoryMap.end()) {
    return false;
  }
  return true;
}

}  // namespace loader
}  // namespace smt
