/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_UTIL_LOGGER_HPP_
#define SMT_UTIL_LOGGER_HPP_

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "thirdParty/spdlog/spdlog.h"
#include "thirdParty/spdlog/sinks/stdout_color_sinks.h"

namespace smt {
namespace util {

using LogerLevel = spdlog::level::level_enum;

class LoggerManager final {
 public:
  static LoggerManager* getInstance() {
    static LoggerManager* singleton = new LoggerManager();
    return singleton;
  }

  void AddLogger(const std::string& loggerName) {
    m_logger[loggerName] = std::make_shared<spdlog::logger>(loggerName, m_sink);
    spdlog::register_logger(m_logger[loggerName]);
  }

  void SetLoggerLevel(const std::string& loggerName, LogerLevel logLevel) {
    m_logger[loggerName]->set_level(logLevel);
  }

 private:
  LoggerManager() {
    m_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    spdlog::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");
  }

 private:
  std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_sink;
  std::map<std::string, std::shared_ptr<spdlog::logger>> m_logger;
};



}  // namespace util
}  // namespace smt

#endif  // SMT_UTIL_LOGGER_HPP_

