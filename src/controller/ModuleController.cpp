/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_CONTROLLER_MODUL_CONTROLLER
#define SMT_CONTROLLER_MODUL_CONTROLLER

#include <vector>
#include <memory>

#include "smt/controller/ModuleController.hpp"

namespace smt {
namespace controller {

ModuleController::ModuleController() : m_handle(smt::base::Handle::GetInstence()),
                                        m_log(spdlog::get(m_handle->GetNodeName())) {}

bool ModuleController::Init() {
    if (!LoadAllModule()) {
        m_log->error("Fail Load Module");
        return false;
    }

    return true;
}

void ModuleController::Clear() {}

bool ModuleController::LoadAllModule() {
    auto args = m_handle->GetArguments();

    for (const auto& moduleIndex : args) {
        if (!LoadMoule(m_handle->GetArguments_map(moduleIndex.first))) {
            m_log->error("ModuleController::Fail Load {} Module", moduleIndex.first);
            return false;
        }
    }
    return true;
}

bool ModuleController::LoadMoule(const json& arg) {
    auto moduleName = arg[JSONKEY_MODULE_NAME].get<std::string>();
    auto className = arg[JSONKEY_MODULE][JSONKEY_CLASS_NAME].get<std::string>();

    m_loadManager.LoadModule(moduleName);

    std::shared_ptr<ModuleBase> base = m_loadManager.CreateClassObj<ModuleBase>(moduleName, className);

    m_moduleLists.emplace_back(std::move(base));

    return true;
}

}  // namespace controller
}  // namespace smt

#endif
