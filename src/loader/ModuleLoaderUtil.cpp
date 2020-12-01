/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include "smt/loader/ModuleLoaderUtil.hpp"

namespace smt {
namespace loader {

ModuleFactoryMap ModuleLoaderUtil::m_factoryMap = ModuleFactoryMap();

bool ModuleLoaderUtil::searchModuleFactorybyClassNeme(const std::string& className) {
  if (m_factoryMap.find(className) == m_factoryMap.end()) {
    return false;
  }
  return true;
}

void ModuleLoaderUtil::releaseModuleFactory(const std::string& className) {
  if (m_factoryMap.find(className) == m_factoryMap.end()) {
    return;
  }

  delete m_factoryMap[className];
  m_factoryMap[className] = nullptr;

  m_factoryMap.erase(className);
}

}  // namespace loader
}  // namespace smt
