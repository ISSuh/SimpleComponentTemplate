/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */


#ifndef SMT_LOADER_MODULEREGISTER_HPP_
#define SMT_LOADER_MODULEREGISTER_HPP_

#include "smt/loader/module_loader_util.hpp"

namespace smt {
namespace loader {

#define MODULE_REGISTER_INTERNAL(UserModuleClass, ModuleBase, UniqueID)    \
namespace {                                                                       \
  struct Proxy##UserModuleClass_##UniqueID {                                      \
    Proxy##UserModuleClass_##UniqueID() {                                         \
        ModuleLoaderUtil::registUserModule<UserModuleClass, ModuleBase>(          \
          #UserModuleClass, #ModuleBase);                                         \
    }                                                                             \
  };                                                                              \
  static Proxy##UserModuleClass_##UniqueID g_registerModule_##UniqueID;           \
}

// register class macro
#define MODULE_REGISTER(UserModuleClass, ModuleBase) \
  MODULE_REGISTER_INTERNAL(UserModuleClass, ModuleBase, __COUNTER__)

// register class macro
#define REGIST_MODULE(UserModuleClass) \
  MODULE_REGISTER_INTERNAL(UserModuleClass, smt::module::Module)

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULEREGISTER_HPP_
