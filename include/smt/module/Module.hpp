/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULE_HPP_
#define SMT_MODULE_MODULE_HPP_

#include <string>
#include <memory>

#include "smt/module/ModuleBase.hpp"
#include "smt/module/ModuleRegister.hpp"
#include "smt/util/JsonWrapper.hpp"

namespace smt {
namespace module {

class Module : public smt::module::ModuleBase {
 protected:
  /**
  * @brief init the user fuction. write your own code.
  *
  * @param 
  *
  * @return returns true if successful, otherwise returns false
  */
  virtual void init() = 0;

  /**
  * @brief run the user fuction. write your own code.
  *
  * @param 
  *
  * @return returns true if successful, otherwise returns false
  */
  virtual void run() = 0;

  /**
  * @brief clear the user fuction. write your own code.
  *
  * @param 
  *
  * @return returns true if successful, otherwise returns false
  */
  virtual void terminate() = 0;

 public:
  Module() = default;
  virtual ~Module() = default;

  bool initialize() override {
    init();
    return true;
  }

  bool process() override {
    run();
    return true;
  }

  bool shutdown() override {
    terminate();
    return true;
  }

  void setArguments(util::JsonWrapper args) {
    m_arguments = args;
  }

  template<typename T>
  void getArgument(const std::string& argumentName, T& var) {
    const T temp = m_arguments[argumentName].get<T>();
    std::copy(&temp, &temp + sizeof(temp), &var);
  }
 private:
  util::JsonWrapper m_arguments;
};

// register class macro
#define REGIST_MODULE(UserModuleClass) \
  MODULE_REGISTER(UserModuleClass, smt::module::Module)

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULE_HPP_
