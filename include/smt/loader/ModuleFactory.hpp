/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULEFACTORY_HPP_
#define SMT_LOADER_MODULEFACTORY_HPP_

#include <string>
#include <memory>

namespace smt {
namespace loader {

class AbstractModuleFactoryBase {
 public:
  AbstractModuleFactoryBase(const std::string& className, const std::string& baseClassName)
      : m_baseClassName(baseClassName), m_className(className) {}

  virtual ~AbstractModuleFactoryBase() = default;

  const std::string getBaseClassName() const {
    return m_baseClassName;
  }

  const std::string getClassName() const {
    return m_className;
  }

 protected:
  const std::string m_baseClassName;
  const std::string m_className;
};

template <typename BaseModule>
class AbstractModlueFactory : public AbstractModuleFactoryBase {
 public:
  AbstractModlueFactory(const std::string& className, const std::string& baseClassName)
      : AbstractModuleFactoryBase(className, baseClassName) {}

  virtual std::shared_ptr<BaseModule> createModule() const = 0;

 private:
  AbstractModlueFactory();
  AbstractModlueFactory(const AbstractModlueFactory &);
  AbstractModlueFactory &operator=(const AbstractModlueFactory &);
};

template <typename UserModule, typename BaseModule>
class ModuleFactory : public AbstractModlueFactory<BaseModule> {
 public:
  ModuleFactory(const std::string& className, const std::string& baseClassName)
      : AbstractModlueFactory<BaseModule>(className, baseClassName) {}

  std::shared_ptr<BaseModule> createModule() const {
    return std::shared_ptr<BaseModule>(new UserModule);
  }
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULEFACTORY_HPP_
