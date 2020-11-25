/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <vector>
#include <memory>

#include "smt/controller/ModuleController.hpp"
#include "smt/util/JsonWrapper.hpp"

namespace smt {
namespace controller {

ModuleController::ModuleController() {}

bool ModuleController::Init() {
  if (!LoadAllModule()) {
    return false;
  }

  return true;
}

void ModuleController::Clear() {}

bool ModuleController::LoadAllModule() {
  return true;
}

// bool ModuleController::LoadMoule(const util::json& arg) {
//   auto moduleName = arg[util::JSONKEY_MODULE_NAME].get<std::string>();
//   auto className = arg[util::JSONKEY_MODULE][util::JSONKEY_CLASS_NAME].get<std::string>();

//   m_loadManager.LoadModule(moduleName);

//   std::shared_ptr<module::ModuleBase> base =
//         m_loadManager.CreateClassObj<module::ModuleBase>(moduleName, className);

//   m_moduleLists.emplace_back(std::move(base));

//   return true;
// }

}  // namespace controller
}  // namespace smt
