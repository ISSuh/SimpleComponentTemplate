/******************************************************************************
 * Copyright 2019 The ISSuh Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef SMT_MODULE_MODULE_BASE_HPP_
#define SMT_MODULE_MODULE_BASE_HPP_

#include <iostream>
#include <memory>
#include <atomic>

namespace smt {
namespace module {

class ModuleBase : public std::enable_shared_from_this<ModuleBase>{
 public:
  ModuleBase() = default;
  virtual ~ModuleBase() = default;

  virtual bool Initialize() { return false; }
  virtual bool Process() { return false; }
  virtual bool Shutdown() { return false; }

 private:
  // std::atomic<bool> m_isShutdown = { false };
  // std::string m_moduleName;
};

}  // namespace module
}  // namespace smt

#endif  // SMT_MODULE_MODULE_BASE_HPP_
