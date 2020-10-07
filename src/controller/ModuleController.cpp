/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_CONTROLLER_MODUL_CONTROLLER
#define SMT_CONTROLLER_MODUL_CONTROLLER

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

// bool ModuleController::LoadMoule(const json& arg) {
    // auto moduleName = arg[JSONKEY_MODULE_NAME].get<std::string>();
    // auto className = arg[JSONKEY_MODULE][JSONKEY_CLASS_NAME].get<std::string>();

    // m_loadManager.LoadModule(moduleName);

    // std::shared_ptr<ModuleBase> base = m_loadManager.CreateClassObj<ModuleBase>(moduleName, className);

    // m_moduleLists.emplace_back(std::move(base));

//     return true;
// }

}  // namespace controller
}  // namespace smt

#endif
