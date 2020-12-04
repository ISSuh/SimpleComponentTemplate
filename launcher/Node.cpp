/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

// #include <dlfcn.h>
#include <iostream>
#include <fstream>
#include <streambuf>

#include "smt/loader/ModuleLoaderManager.hpp"
#include "smt/loader/ModuleLoader.hpp"

int main() {
  std::cout << "SimpleModule Node" << std::endl;

  const std::string TEST_MODULE_JSON_PATH =
      "/home/issuh/workspace/myProject/SimpleModule/example/hello_world/hello_world_conf.json";

  std::ifstream jsonFile(TEST_MODULE_JSON_PATH);
  std::string jsonStr((std::istream_iterator<char>(jsonFile)),
                      std::istream_iterator<char>());

  smt::loader::ModuleLoadManager loaderManager;
  loaderManager.createModlueLoader(smt::util::JsonWrapper(jsonStr));

  loaderManager.loadAllModule();

  auto userModule0 = loaderManager.getModule("Sample_0");
  auto userModule1 = loaderManager.getModule("Sample_1");

  userModule0->initialize();
  userModule0->process();
  userModule0->shutdown();

  userModule1->initialize();
  userModule1->process();
  userModule1->shutdown();

  loaderManager.unLoadAllModule();
}
