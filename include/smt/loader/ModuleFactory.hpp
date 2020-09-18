/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULEFACTORY_HPP_
#define SMT_LOADER_MODULEFACTORY_HPP_

#include <dlfcn.h>

#include <string>
#include <map>
#include <memory>

#include "smt/base/handle.hpp"
#include "smt/loader/ModuleLoader.hpp"

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
  std::string m_baseClassName;
  std::string m_className;
};

template <typename Base>
class AbstractModlueFactory : public AbstractModuleFactoryBase {
public:
  AbstractModlueFactory(const std::string& className, const std::string& baseClassName)
      : AbstractModuleFactoryBase(className, baseClassName) {}

  virtual Base *CreateObj() const = 0;

 private:
  AbstractModlueFactory();
  AbstractModlueFactory(const AbstractModlueFactory &);
  AbstractModlueFactory &operator=(const AbstractModlueFactory &);
};

template <typename ModuleObject, typename Base>
class ModuleFactory : AbstractModlueFactory<Base> {
 public:
  ModuleFactory(const std::string& className, const std::string& baseClassName)
      : AbstractModlueFactory<Base>(className, baseClassName) {}

  Base *CreateObj() const {
    return new ModuleObject;
  }
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULEFACTORY_HPP_