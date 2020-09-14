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

class Module : public smt::module::ModuleBase{
 public:
  Module() = default;
  virtual ~Module() = default;

  bool Initialize() override {
    if (!init()) {
      return false;
    }

    return true;
  }

  bool Process() override {
    if (!run()) {
      return false;
    }

    return true;
  }

  bool Shutdown() override {
    if (!terminate()) {
      return false;
    }

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
  virtual bool init() = 0;

  /**
  * @brief run the user fuction. write your own code.
  *
  * @param 
  *
  * @return returns true if successful, otherwise returns false
  */
  virtual bool run() = 0;

  /**
  * @brief clear the user fuction. write your own code.
  *
  * @param 
  *
  * @return returns true if successful, otherwise returns false
  */
  virtual bool terminate() = 0;

 private:
};

#define REGISTER_MODULE(name) \
CLASS_LOADER_REGISTER_CLASS(name, smt::module::ModuleBase)

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULE_HPP_
