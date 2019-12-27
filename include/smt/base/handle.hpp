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

namespace smt {

namespace base {

using json = nlohmann::json;
using namespace smt::util; 

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
    static Handle* GetInstence(const std::map<std::string, json>& moduleArgs){
        if(m_instance == nullptr) {
            std::lock_guard<std::mutex> lock(m_mutex);
            if(m_instance == nullptr) {
                m_instance = new Handle(moduleArgs);
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
    void Init() {
        // Set Logger
        {
            m_nodeName = m_modulsArgs[JSONKEY_NODE_NAME].get<std::string>();

            m_logger.AddLogger(m_nodeName);
            m_log = spdlog::get(m_nodeName);

            for(auto& i : m_modulsArgs){
                m_logger.AddLogger(i.second[JSONKEY_MODULE][JSONKEY_CLASS_NAME].get<std::string>());
            }
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
    const std::map<std::string, json>& GetAllArguments(){
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_modulsArgs;
    }

    /**
    * @brief Get module's argument globally
    *
    * @param const std::string& name of user modules
    *
    * @return returns json about user module's arguments
    */
    const json& GetArguments_map(const std::string& moduleName){
        std::lock_guard<std::mutex> lock(m_mutex);
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
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_modulsArgs.size();
    }

    /**
    * @brief Get number of user modules
    *
    * @param 
    *
    * @return returns number of user modules
    */
    const std::string& GetNodeName() const {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_nodeName;
    }

    Handle(Handle const&) = delete;
    void operator=(Handle const&) = delete;

protected :
    Handle(const std::map<std::string, json>& moduleArgs) : m_modulsArgs(moduleArgs) {};

private:

private:
    std::shared_ptr<spdlog::logger> m_log;
    Logger m_logger;

    static std::atomic<Handle*> m_instance;
    static std::mutex m_mutex;

    std::map<std::string, json> m_modulsArgs;

    std::atomic<bool> m_isRunning = { false };

    std::string m_nodeName;
};

std::atomic<Handle*> Handle::m_instance { nullptr };
std::mutex Handle::m_mutex;

} // namespace base

} // namespace smt

#endif
