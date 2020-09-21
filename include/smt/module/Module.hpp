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

typedef Module* CreateModuleHandler();
typedef void DestroyModuleHandler(Module*);

#define CREATE_MODULE(CLASS_NAME, BASE_MODULE)  \
extern "C" BASE_MODULE* createModule() {        \
  return new CLASS_NAME()                       \
}

#define DESTROY_MODULE(BASE_MODULE)                       \
extern "C" void DESTROY_MODULE(BASE_MODULE* module) {     \
  delete module;                                          \
}

#define REGIST_MODULE(name)                \
CREATE_MODULE(name, smt::module::Module)   \
DESTROY_MODULE(smt::module::Module)

// #define REGIST_MODULE(name) \
// CLASS_LOADER_REGISTER_CLASS(name, smt::module::Module)

// #define CLASS_LOADER_REGISTER_CLASS(CLASS_NAME, BASE_MODULE) \
// struct CLASS_NAMEProxy { \
//   static BASE_MODULE* createModule() { \
//       return new CLASS_NAME(); \
//   } \
//   static void destroyModule(BASE_MODULE* node) { \
//     delete node; \
//   } \
// };

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULE_HPP_
