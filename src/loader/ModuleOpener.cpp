/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>

#include "smt/loader/ModuleOpener.hpp"
#include "smt/module/ModuleBase.hpp"

namespace smt {
namespace loader {

std::vector<std::unique_ptr<uint8_t, std::function<void(uint8_t*)>>> ModuleOpener::m_dlHandles;

void ModuleOpener::moduleOpen(const std::string& path, int mode) {
  std::cout << "ModuleOpener::moduleOpen - " << path << std::endl;

  uint8_t* moduleHandle = static_cast<uint8_t*>(dlopen(path.c_str(), mode));
  if (moduleHandle == nullptr) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  m_dlHandles.emplace_back(std::move(moduleHandle), ModuleOpener::dlHandleDeletor);
}

void ModuleOpener::dlHandleDeletor(uint8_t* hadle) {
  dlclose(static_cast<void*>(hadle));
}

}  // namespace loader
}  // namespace smt
