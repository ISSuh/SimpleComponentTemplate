/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <string>

#include "smt/module/ModuleInfo.hpp"

namespace smt {
namespace module {

UserModuleInfo::UserModuleInfo()
  : BaseModuleInfo("Module", "Module"),
    m_userModuleName(""),
    m_userClassName(""),
    m_modulePath(""),
    m_moduleArgs(),
    m_moduleConfigure() {}

bool UserModuleInfo::parseModueInfoOnJson(util::JsonWrapper info) {
  if (!info.hasKey(util::JSONKEY::MODULE_NAME)) {
    std::cout << "UserModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [module_name]" << std::endl;
    return false;
  }
  setUserModuleName(info[util::JSONKEY::MODULE_NAME].get<std::string>());

  if (!info.hasKey(util::JSONKEY::MODULE_PATH)) {
    std::cout << "UserModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [module_path]" << std::endl;
    return false;
  }
  setModulePath(info[util::JSONKEY::MODULE_PATH].get<std::string>());

  if (!info.hasKey(util::JSONKEY::MODULE)) {
    std::cout << "UserModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [Module]" << std::endl;
    return false;
  }

  if (info[util::JSONKEY::MODULE].hasKey(util::JSONKEY::CLASS_NAME)) {
    std::cout << "UserModuleInfo::parseModueInfoOnJson - "
              << " Parse Error. Chek json key [class_name]" << std::endl;
    return false;
  }
  setUserClassName(info[util::JSONKEY::MODULE][util::JSONKEY::CLASS_NAME].get<std::string>());

  if (info[util::JSONKEY::MODULE].hasKey(util::JSONKEY::ARGS)) {
    setModuleArgs(info[util::JSONKEY::MODULE][util::JSONKEY::CONFIGURE]);
  }

  if (info[util::JSONKEY::MODULE].hasKey(util::JSONKEY::CONFIGURE)) {
    setModuleConfigure(info[util::JSONKEY::MODULE][util::JSONKEY::CONFIGURE]);
  }

  return true;
}

void UserModuleInfo::setUserModuleName(const std::string& moduleName) {
  m_userModuleName = moduleName;
}
void UserModuleInfo::setUserClassName(const std::string& className) {
  m_userClassName = className;
}
void UserModuleInfo::setModulePath(const std::string& modulePath) {
  m_modulePath = modulePath;
}
void UserModuleInfo::setModuleArgs(const util::JsonWrapper& args) {
  m_moduleArgs = args;
}
void UserModuleInfo::setModuleConfigure(const util::JsonWrapper& configures) {
  m_moduleConfigure = configures;
}

}  // namespace module
}  // namespace smt

