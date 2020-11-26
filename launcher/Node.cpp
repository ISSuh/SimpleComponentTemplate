/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

// #include <dlfcn.h>
#include <iostream>

#include "smt/loader/ModuleLoaderUtil.hpp"
#include "smt/loader/ModuleLoader.hpp"

const char* TEST_MODULE_PATH = "/home/issuh/workspace/myProject/SimpleModule/build/lib/libhello_world.so";

int main() {
  std::cout << "SimpleModule Node" << std::endl;

  void* module1 = dlopen(TEST_MODULE_PATH, RTLD_LAZY | RTLD_GLOBAL);
  if (!module1) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  smt::loader::ModuleLoader loader;

  auto userModule = loader.createModule<smt::module::Module>("SampleModule");

  userModule->initialize();
  userModule->process();
  userModule->shutdown();

  // loader.unLoadModule("test");
  loader.unLoadModule("SampleModule");
}
