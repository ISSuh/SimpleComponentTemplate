/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_UTIL_JSONWRAPPER_HPP_
#define SMT_UTIL_JSONWRAPPER_HPP_

#include <string>
#include "smt/util/thirdParty/json/json.hpp"

namespace smt {
namespace util {

using json = nlohmann::json;

class JSONKEY {
 public:
  static const char* NODE_NAME;
  static const char* LOG_LEVEL;
  static const char* MODULES;
  static const char* MODULE_NAME;
  static const char* MODULE_PATH;
  static const char* MODULE;
  static const char* CLASS_NAME;
  static const char* CONFIGURE;
  static const char* THREADING;
  static const char* ARGS;
};

class JsonWrapper {
 public:
  JsonWrapper() : m_jsonObj() {}
  explicit JsonWrapper(const char* jsonStr) { m_jsonObj = json::parse(jsonStr); }
  explicit JsonWrapper(const std::string& jsonStr) { m_jsonObj = json::parse(jsonStr); }
  JsonWrapper(const JsonWrapper& json) {
    clear();
    m_jsonObj = json.m_jsonObj;
  }

  virtual ~JsonWrapper() = default;

  void parse(const char* jsonStr) {
    clear();
    m_jsonObj = json::parse(jsonStr);
  }

  void parse(const std::string& jsonStr) {
    clear();
    m_jsonObj = json::parse(jsonStr);
  }

  template<class T>
  T get() { return m_jsonObj; }

  const std::string dump() const { return m_jsonObj.dump(); }

  void clear() { m_jsonObj.clear(); }
  uint32_t size() const { return m_jsonObj.size(); }

  bool empty() const { return m_jsonObj.empty(); }
  bool hasKey(const std::string& key) { return m_jsonObj.find(key) != m_jsonObj.end(); }
  bool hasKey(const char* key) { return m_jsonObj.find(key) != m_jsonObj.end(); }
  bool hasIndex(int index) { return m_jsonObj[index].empty(); }

  bool getBool(const std::string& key) const { return m_jsonObj[key]; }
  int32_t getInt(const std::string& key) const { return m_jsonObj[key]; }
  uint32_t getUint(const std::string& key) const  { return m_jsonObj[key]; }
  const std::string getString(const std::string& key) const { return m_jsonObj[key]; }

  JsonWrapper& operator=(const JsonWrapper& rhs) {
    if (&rhs != this) {
      return *this;
    }

    clear();
    m_jsonObj = rhs.m_jsonObj;

    return *this;
  }

  JsonWrapper operator[](const char* key) { return JsonWrapper(m_jsonObj[key].dump()); }
  JsonWrapper operator[](const std::string& key) { return JsonWrapper(m_jsonObj[key].dump()); }
  JsonWrapper operator[](int index) { return JsonWrapper(m_jsonObj.at(index).dump()); }

 private:
  json m_jsonObj;
};

}  // namespace util
}  // namespace smt

#endif  // SMT_UTIL_JSONWRAPPER_HPP_
