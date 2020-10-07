/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#include <iostream>

#include "hello_world_module.hpp"

void SampleModule::init() {
  str = "Hello World!";
  // GetParam("int_test", m_int_test);
  // GetParam("float_test", m_float_test);
  // GetParam("bool_test", m_bool_test);
  // GetParam("string_test", m_string_test);
}

void SampleModule::run() {
  std::cout << str << '\n';
}

void SampleModule::terminate() {
  std::cout << "SampleModule::terminate()" << '\n';
}
