/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

// #include <dlfcn.h>
#include <iostream>
#include <fstream>
#include <streambuf>

#include "smt/loader/ModuleLoaderUtil.hpp"
#include "smt/loader/ModuleLoader.hpp"
#include "smt/loader/ModuleOpener.hpp"

int main() {
  std::cout << "SimpleModule Node" << std::endl;

  const std::string TEST_MODULE_PATH =
      "/home/issuh/workspace/myProject/SimpleModule/build/lib/libhello_world.so";
  const std::string TEST_MODULE_JSON_PATH =
      "/home/issuh/workspace/myProject/SimpleModule/example/hello_world/hello_world_conf.json";

  std::ifstream jsonFile(TEST_MODULE_JSON_PATH);
  std::string jsonStr((std::istream_iterator<char>(jsonFile)),
                      std::istream_iterator<char>());

  smt::loader::ModuleOpener::moduleOpen(TEST_MODULE_PATH);
  smt::loader::ModuleLoader loader;

  auto userModule = loader.createModule<smt::module::Module>("SampleModule");

  userModule->initialize();
  userModule->process();
  userModule->shutdown();

  // loader.unLoadModule("test");
  loader.unLoadModule("SampleModule");
}
