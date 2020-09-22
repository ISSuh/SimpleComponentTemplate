/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */


#ifndef SMT_LOADER_MODULEREGIST_HPP_
#define SMT_LOADER_MODULEREGIST_HPP_

#include "smt/loader/module_loader_util.hpp"

namespace smt {
namespace loader {


class 
#define MODULE_LOADER_REGISTER_INTERNAL(UserModuleClass, ModuleBase, UniqueID)    \
namespace {                                                                       \
  struct Proxy##UserModuleClass_##UniqueID {                                      \
    Proxy##UserModuleClass_##UniqueID() {                                         \
        smt::loader::util::registUserModule<UserModuleClass, ModuleBase>(         \
          #UserModuleClass, #ModuleBase);                                         \
    }                                                                             \
  };                                                                              \
  static Proxy##UserModuleClass_##UniqueID g_registerModule_##UniqueID;           \
}

// register class macro
#define MODULE_LOADER_REGISTER(UserModuleClass, ModuleBase) \
  MODULE_LOADER_REGISTER_INTERNAL(UserModuleClass, ModuleBase, __COUNTER__)

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULEREGIST_HPP_
