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

#ifndef SMT_BASE_HANDLE
#define SMT_BASE_HANDLE

#include <atomic>
#include <mutex>
#include <memory>
#include <map>
#include <fstream>
#include <chrono>
#include <thread>

#include <smt/util/logger.hpp>
#include <smt/util/json_key.hpp>

#include <3thParty/json/json.hpp>
#include <3thParty/spdlog/spdlog.h>

using json = nlohmann::json;
using namespace smt::util; 

namespace smt {

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
    
    /**
    * @brief Get handle for globally
    *
    * @param 
    *
    * @return returns static Handle object
    */
    static Handle* GetInstence(){
        if(m_instance == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if(m_instance == nullptr) {
                m_instance = new Handle();
            }
        }

        return m_instance;
    }

    /**
    * @brief init Handle
    *
    * @param const std::vector<std::string>& path of configure JSON
    *
    * @return void
    */
    void Init(const std::vector<std::string>& configJsonPath) {
        m_logger.AddLogger("Handle");
        m_log = spdlog::get("Handle");

        for(auto& i : configJsonPath){
            ParseJsonFile(i);
        }

        for(auto& i : m_modulsArgs){
            m_logger.AddLogger(i.second[JSONKEY_MODULE][JSONKEY_CLASS_NAME].get<std::string>());
        }
    };

    /**
    * @brief wait for user components
    *
    * @param int rate of millisecond sleep
    *
    * @return void
    */
    void WaitForModule(const int& rate) {
        while(m_isRunning.load()){
            std::this_thread::sleep_for(std::chrono::milliseconds(rate));
        }
    };

    /**
    * @brief shutdown main node 
    *
    * @param 
    *
    * @return void
    */
    void Shutdown() {

    };

    /**
    * @brief Get module's argument globally
    *
    * @param const std::string& name of user modules
    *
    * @return returns json about user module's arguments
    */
    const json& GetParsedArguments(const std::string& moduleName){
        return m_modulsArgs[moduleName];
    }

    /**
    * @brief Get number of user modules
    *
    * @param 
    *
    * @return returns number of user modules
    */
    const size_t GetModulsNum() const {
        return m_numModuls;
    }

    Handle(Handle const&) = delete;
    void operator=(Handle const&) = delete;

protected :
    Handle() {};

private:
    /**
    * @brief Parse user module's argument
    *
    * @param const std::string& JSON file path
    *
    * @return returns true if successful, otherwise returns false
    */
    bool ParseJsonFile(const std::string& filePath){
        std::ifstream readFile(filePath);
        json arg = json::parse(readFile);

        for(auto& i : arg[JSONKEY_MODULES]){
            const std::string moduleName = i[JSONKEY_MODULE_NAME].get<std::string>();
            
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
    Logger m_logger;

    static std::atomic<Handle*> m_instance;
    static std::mutex m_mutex;

    std::map<std::string, json> m_modulsArgs;
    size_t m_numModuls;

    std::atomic<bool> m_isRunning = { false };
};

std::atomic<Handle*> Handle::m_instance { nullptr };
std::mutex Handle::m_mutex;

} // namespace base

} // namespace smt

#endif
