/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULEINFO_HPP_
#define SMT_MODULE_MODULEINFO_HPP_

#include <string>

#include "smt/util/JsonWrapper.hpp"

namespace smt {
namespace module {

class BaseModuleInfo {
 public:
  BaseModuleInfo(const std::string& baseModuleName, const std::string& baseClassName)
      : m_baseModuleName(baseModuleName), m_baseClassName(baseClassName) {}
  virtual ~BaseModuleInfo() = default;

  const std::string getBaseModuleName() const { return m_baseModuleName; }
  const std::string getBaseClassName() const { return m_baseClassName; }

 protected:
  const std::string m_baseModuleName;
  const std::string m_baseClassName;
};

class UserModuleInfo : public BaseModuleInfo {
 public:
  UserModuleInfo(const std::string& userModuleName, const std::string& userClassName)
      : BaseModuleInfo("Module", "Module") {}
  virtual ~UserModuleInfo() = default;

  const std::string getUserModuleName() const { return m_userModuleName; }
  const std::string getUserClassName() const { return m_userClassName; }
  const std::string getModulePath() const {return m_modulePath; }
  const smt::util::JsonWrapper getModuleArgs() const { return m_moduleArgs; }
  const smt::util::JsonWrapper getModuleConfigure() const { return m_moduleConfigure; }

  void setUserModuleName(const std::string& moduleName) { m_userModuleName = moduleName; }
  void setUserClassName(const std::string& className) { m_userClassName = className; }
  void setModulePath(const std::string& modulePath) { m_modulePath = modulePath; }
  void setModuleArgs(const smt::util::JsonWrapper& args)  { m_moduleArgs = args; }
  void setModuleConfigure(const smt::util::JsonWrapper config) { m_moduleConfigure = config; }

 protected:
  std::string m_userModuleName;
  std::string m_userClassName;
  std::string m_modulePath;
  smt::util::JsonWrapper m_moduleArgs;
  smt::util::JsonWrapper m_moduleConfigure;
};

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULEINFO_HPP_
