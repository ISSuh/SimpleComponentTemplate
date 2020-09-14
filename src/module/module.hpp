/******************************************************************************
 * Copyright 2019 The ISSuh Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef SMT_MODULE_MODULE_HPP_
#define SMT_MODULE_MODULE_HPP_

#include <iostream>
#include <memory>

#include <smt/module/module_base.hpp>

namespace smt {

namespace module {

class Module : public smt::module::ModuleBase{
 public:
  Module() = default;
  virtual ~Module() = default;

  bool Initialize() override {
    if (!Init()) {
      return false;
    }

    return true;
  }

  bool Process() override {
    if (!Run()) {
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
