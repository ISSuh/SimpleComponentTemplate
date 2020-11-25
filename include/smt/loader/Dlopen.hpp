/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_LINUX_DLOPEN_HPP_
#define SMT_LOADER_LINUX_DLOPEN_HPP_

#include <dlfcn.h>

#include <string>
#include <memory>

#include "smt/module/Module.hpp"

namespace smt {
namespace loader {

class Dlopen {
 public:
  Dlopen() {}
  ~Dlopen() {}

 private:
  
}

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_LINUX_DLOPEN_HPP_