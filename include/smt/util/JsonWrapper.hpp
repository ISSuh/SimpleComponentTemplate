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

#ifndef SMT_UTIL_JSONWRAPPER_HPP_
#define SMT_UTIL_JSONWRAPPER_HPP_

#include <string>
#include <smt/util/thirdParty/json/json.hpp>

namespace smt {
namespace util {

using json = nlohmann::json;

const char* JSONKEY_NODE_NAME   = "node_name";
const char* JSONKEY_LOG_LEVEL   = "log_level";
const char* JSONKEY_MODULES     = "modules";
const char* JSONKEY_MODULE_NAME = "module_name";
const char* JSONKEY_MODULE_PATH = "module_path";
const char* JSONKEY_MODULE      = "module";
const char* JSONKEY_CLASS_NAME  = "class_name";
const char* JSONKEY_CONFIGURE   = "configure";
const char* JSONKEY_THREADING   = "threading";
const char* JSONKEY_ARGS        = "args";

class JsonWrapper {
 public:
  explicit JsonWrapper(const char* jsonStr) { m_jsonObj = jsonStr; }
  explicit JsonWrapper(const std::string& jsonStr) { m_jsonObj = jsonStr.c_str(); }

  virtual ~JsonWrapper() = default;

  bool getBool(const std::string& key) const { return m_jsonObj[key]; }
  int32_t getInt(const std::string& key) const { return m_jsonObj[key]; }
  uint32_t getUint(const std::string& key) const  { return m_jsonObj[key]; }
  const std::string getString(const std::string& key) const { return m_jsonObj[key]; }

 private:
  json m_jsonObj;
};

}  // namespace util
}  // namespace smt

#endif  // SMT_UTIL_JSONWRAPPER_HPP_
