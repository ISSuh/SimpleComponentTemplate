/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_LOADER_MODULEOPENER_HPP_
#define SMT_LOADER_MODULEOPENER_HPP_

#include <dlfcn.h>

#include <string>
#include <vector>
#include <memory>

namespace smt {
namespace loader {

class ModuleOpener {
 public:
  static void moduleOpen(const std::string& path, int mode = RTLD_LAZY | RTLD_GLOBAL);

 private:
  static void dlHandleDeletor(uint8_t* hadle);

 private:
  static std::vector<std::unique_ptr<uint8_t, std::function<void(uint8_t*)>>> m_dlHandles;
};

}  // namespace loader
}  // namespace smt

#endif  // SMT_LOADER_MODULEOPENER_HPP_
