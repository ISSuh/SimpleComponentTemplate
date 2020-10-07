/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULEREGISTER_HPP_
#define SMT_MODULE_MODULEREGISTER_HPP_

#include "smt/loader/ModuleLoaderUtil.hpp"

namespace smt {
namespace module {

#define MODULE_REGISTER_INTERNAL(UserModuleClass, ModuleBase, UniqueID)                 \
namespace {                                                                             \
  struct Proxy##UserModuleClass_##UniqueID {                                            \
    Proxy##UserModuleClass_##UniqueID() {                                               \
        smt::loader::ModuleLoaderUtil::registUserModule<UserModuleClass, ModuleBase>(   \
          #UserModuleClass, #ModuleBase);                                               \
    }                                                                                   \
  };                                                                                    \
  static Proxy##UserModuleClass_##UniqueID g_registerModule_##UniqueID;                 \
}

// register class macro
#define MODULE_REGISTER(UserModuleClass, ModuleBase) \
  MODULE_REGISTER_INTERNAL(UserModuleClass, ModuleBase, __COUNTER__)

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULEREGISTER_HPP_
