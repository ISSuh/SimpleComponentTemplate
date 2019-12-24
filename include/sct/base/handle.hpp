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

#ifndef SCT_BASE_HANDLE
#define SCT_BASE_HANDLE

#include <atomic>
#include <mutex>
#include <memory>
#include <map>
#include <fstream>

#include <sct/util/logger.hpp>
#include <sct/util/json_key.hpp>

#include <3thParty/json/json.hpp>
#include <3thParty/spdlog/spdlog.h>

using json = nlohmann::json;

namespace sct {

namespace base {

// TODO : Implement Singleton Class
/**
 *  Handle Class
 *  
 *  Init argument & return argument for every user module
 *  Init schduler
 *  Wait for user module
 *  Clear & Shutdown all module 
 * 
 **/

class Handle{
public:
    static Handle* GetInstence(){
        if(m_instance == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if(m_instance == nullptr) {
                m_instance = new Handle();
            }
        }

        return m_instance;
    }

    void Init(const std::vector<std::string>& configJsonPath) {
        m_logger.AddLogger("Handle");
        m_log = spdlog::get("Handle");

        for(auto& i : configJsonPath){
            ParseJsonFile(i);
        }

        for(auto& i : m_modulsArgs){
            m_logger.AddLogger(i.second[JSONKEY_COMPONEMTS][JSONKEY_CLASS_NAME].get<std::string>());
        }
    };

    void WaitForModule() {};

    void Shutdown() {};

    const json& GetParsedArguments(const std::string& moduleName){
        return m_modulsArgs[moduleName];
    }

    const size_t GetModulsNum() const {
        return m_numModuls;
    }

    Handle(Handle const&) = delete;
    void operator=(Handle const&) = delete;

protected :
    Handle() {};

private:
    bool ParseJsonFile(const std::string& filePath){
        std::ifstream readFile(filePath);
        json arg = json::parse(readFile);

        for(auto& i : arg[JSONKEY_MODULES]){
            const std::string moduleName = i[JSONKEY_NAME].get<std::string>();
            
            if(m_modulsArgs.find(moduleName) != m_modulsArgs.end()){
                m_log->error("Same Module Name!");
                exit(0);
            }
            
            m_modulsArgs[moduleName] = i;
            ++m_numModuls;
        }

        return true;
    }

private:
    std::shared_ptr<spdlog::logger> m_log;

    static std::atomic<Handle*> m_instance;
    static std::mutex m_mutex;

    sct::util::Logger m_logger;

    std::map<std::string, json> m_modulsArgs;
    size_t m_numModuls;

};

std::atomic<Handle*> Handle::m_instance { nullptr };
std::mutex Handle::m_mutex;

} // namespace base

} // namespace sct

#endif
