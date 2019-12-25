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

#ifndef SCT_UTIL_LOGGER
#define SCT_UTIL_LOGGER

#include <iostream>
#include <memory>
#include <map>

#include <3thParty/spdlog/spdlog.h>
#include <3thParty/spdlog/sinks/stdout_color_sinks.h>

namespace sct{

namespace util{

using LogerLevel = spdlog::level::level_enum;

class Logger final {
public:
    Logger(){
        m_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        spdlog::set_pattern("*** [%H:%M:%S %z] [thread %t] %v ***");
    };

    void AddLogger(const std::string& loggerName){
        m_logger[loggerName] = std::make_shared<spdlog::logger>(loggerName, m_sink);      
        spdlog::register_logger(m_logger[loggerName]);
    }

    void SetLoggerLevel(const std::string& loggerName, LogerLevel logLevel){
        m_logger[loggerName]->set_level(logLevel);
    }

private:
    std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> m_sink;
    std::map<std::string, std::shared_ptr<spdlog::logger>> m_logger;
};

} // namespace utin

} // namespace sct

#endif
