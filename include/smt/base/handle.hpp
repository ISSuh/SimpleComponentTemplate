/**
 * Copyright 2020 The ISSuh Authors. All Rights Reserved.
 * Distributed under the MIT License (http://opensource.org/licenses/MIT)
 */

#ifndef SMT_BASE_HANDLE
#define SMT_BASE_HANDLE

#include <map>
#include <atomic>
#include <memory>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>

#include "smt/util/logger.hpp"
#include "smt/util/json_key.hpp"

#include "thirdParty/json/json.hpp"
#include "thirdParty/spdlog/spdlog.h"

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
    void Init(const std::vector<json>& configJson) {
        // Set arguments, arguments map
        {
            m_configJson = std::move(configJson);
            MakeArgumentsMap(m_configJson);

            m_nodeName = m_configJson[0][JSONKEY_NODE_NAME].get<std::string>();
            m_logLevel = m_configJson[0][JSONKEY_LOG_LEVEL].get<std::string>();
        }
        // Set Logger
        {
            m_logger.AddLogger(m_nodeName);
            m_log = spdlog::get(m_nodeName);

            for(auto& i : m_modulsArgs){
                m_logger.AddLogger(i.second[JSONKEY_MODULE_NAME].get<std::string>());
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
    const std::map<std::string, json>& GetArguments(){
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

public:
    Handle(Handle const&) = delete;
    void operator=(Handle const&) = delete;

protected :
    Handle() {}

private :
    void MakeArgumentsMap(const std::vector<json>& configJson){
        for(auto& argJson : configJson){
            for(auto& i : argJson[JSONKEY_MODULES]){
                const std::string moduleName = i[JSONKEY_MODULE_NAME].get<std::string>();
                
                if(m_modulsArgs.find(moduleName) != m_modulsArgs.end()){
                    spdlog::error("Same Module Name!");
                    exit(0);
                }
                
                m_modulsArgs[moduleName] = i;
            }
        }
    }

private:
    std::shared_ptr<spdlog::logger> m_log;
    Logger m_logger;

    static std::atomic<Handle*> m_instance;
    static std::mutex m_mutex;

    std::vector<json> m_configJson;
    std::map<std::string, json> m_modulsArgs;

    std::atomic<bool> m_isRunning = { false };

    std::string m_nodeName;
    std::string m_logLevel;

};

std::atomic<Handle*> Handle::m_instance { nullptr };
std::mutex Handle::m_mutex;

} // namespace base

} // namespace smt

#endif
