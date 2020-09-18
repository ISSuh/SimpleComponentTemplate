/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULE_HPP_
#define SMT_MODULE_MODULE_HPP_

#include <iostream>
#include <memory>

#include "smt/module/ModuleBase.hpp"

namespace smt {
namespace module {

class Module : public smt::module::ModuleBase {
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

 private:
};

#define REGIST_MODULE(name) \
CLASS_LOADER_REGISTER_CLASS(name, smt::module::ModuleBase)

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULE_HPP_