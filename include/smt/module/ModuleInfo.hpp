/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULEINFO_HPP_
#define SMT_MODULE_MODULEINFO_HPP_

#include <string>

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
      : BaseModuleInfo("Module", "Module"),
        m_userModuleName(userModuleName), m_userClassName(userClassName) {}
  virtual ~UserModuleInfo() = default;

  const std::string getUserModuleName() const { return m_baseModuleName; }
  const std::string getUserClassName() const { return m_baseClassName; }

 protected:
  const std::string m_userModuleName;
  const std::string m_userClassName;
};

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULEINFO_HPP_
