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
  smt::module::Module* module = nullptr;

  std::cout << "Hello World! - " << std::endl;

  smt::loader::ModuleLoaderUtil::registUserModule<int, int>("test", "tret");

  void* module1 = dlopen(TEST_MODULE_PATH, RTLD_LAZY | RTLD_GLOBAL);
  if (!module1) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  auto userModule1 = smt::loader::ModuleLoaderUtil::createUserModule<int>("test");
  auto userModule2 = smt::loader::ModuleLoaderUtil::createUserModule<smt::module::Module>("SampleModule");

  userModule2->initialize();
  userModule2->process();
  userModule2->shutdown();
}
