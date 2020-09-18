/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_MODULE_MODULEBASE_HPP_
#define SMT_MODULE_MODULEBASE_HPP_

#include <iostream>
#include <memory>
#include <atomic>

namespace smt {
namespace module {

class ModuleBase : public std::enable_shared_from_this<ModuleBase> {
 public:
  ModuleBase() = default;
  virtual ~ModuleBase() = default;

  virtual bool initialize() { return false; }
  virtual bool process() { return false; }
  virtual bool shutdown() { return false; }

 private:
  // std::atomic<bool> m_isShutdown = { false };
  // std::string m_moduleName;
};

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULEBASE_HPP_
