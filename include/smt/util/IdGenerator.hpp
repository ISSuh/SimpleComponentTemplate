/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_UTIL_IDGENERATOR_HPP_
#define SMT_UTIL_IDGENERATOR_HPP_

#include <random>

namespace smt {
namespace util {

uint64_t idGenerator() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<uint64_t> distribution;

  return distribution(gen);
}

}  // namespace util
}  // namespace smt

#endif  // SMT_UTIL_IDGENERATOR_HPP_
