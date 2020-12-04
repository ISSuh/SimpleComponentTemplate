/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <string>

#include "smt/module/ModuleInfo.hpp"

namespace smt {
namespace module {

ModuleInfo::ModuleInfo()
  : BaseModuleInfo("Module", "Module"),
    m_moduleName(""),
    m_className(""),
    m_modulePath(""),
    m_moduleArgs(),
    m_moduleConfigure() {}

bool ModuleInfo::parseModueInfoOnJson(util::JsonWrapper info) {
  if (!info.hasKey(util::JSONKEY::MODULE_NAME)) {
    std::cout << "ModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [module_name]" << std::endl;
    return false;
  }
  setModuleName(info[util::JSONKEY::MODULE_NAME].get<std::string>());

  if (!info.hasKey(util::JSONKEY::MODULE_PATH)) {
    std::cout << "ModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [module_path]" << std::endl;
    return false;
  }
  setModulePath(info[util::JSONKEY::MODULE_PATH].get<std::string>());

  if (!info.hasKey(util::JSONKEY::MODULE)) {
    std::cout << "ModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [Module]" << std::endl;
    return false;
  }

  util::JsonWrapper moduleInfo(info[util::JSONKEY::MODULE]);

  if (!moduleInfo.hasKey(util::JSONKEY::CLASS_NAME)) {
    std::cout << "ModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [class_name]" << std::endl;
    return false;
  }
  setClassName(info[util::JSONKEY::MODULE][util::JSONKEY::CLASS_NAME].get<std::string>());

  if (!moduleInfo.hasKey(util::JSONKEY::ARGS)) {
    setModuleArgs(info[util::JSONKEY::MODULE][util::JSONKEY::CONFIGURE]);
  }

  if (!moduleInfo.hasKey(util::JSONKEY::CONFIGURE)) {
    setModuleConfigure(info[util::JSONKEY::MODULE][util::JSONKEY::CONFIGURE]);
  }

  return true;
}

void ModuleInfo::setModuleName(const std::string& moduleName) {
  m_moduleName = moduleName;
}
void ModuleInfo::setClassName(const std::string& className) {
  m_className = className;
}
void ModuleInfo::setModulePath(const std::string& modulePath) {
  m_modulePath = modulePath;
}
void ModuleInfo::setModuleArgs(const util::JsonWrapper& args) {
  m_moduleArgs = args;
}
void ModuleInfo::setModuleConfigure(const util::JsonWrapper& configures) {
  m_moduleConfigure = configures;
}

}  // namespace module
}  // namespace smt

