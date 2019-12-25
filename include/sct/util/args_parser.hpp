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

#ifndef SCT_UTIL_ARG_PARSER
#define SCT_UTIL_ARG_PARSER

#include <iostream>
#include <getopt.h>
#include <vector>

#include <3thParty/spdlog/spdlog.h>

namespace sct {

namespace util {

class ArgParser final {
public:    
    void ParseArguments(const int argc, char* const* argv){
        ParseOptions(argc, argv);
    }

    std::vector<std::string> GetConfgJsonParh() const{
        return m_configJsonPath;
    }

private:
    void Usage() {
        spdlog::info("Display");
    }

    void ParseOptions(const int argc, char* const* argv){
        opterr = 0;  // extern int opterr
        int optionsIndex = 0;
        const std::string shortOptions = "hc:";
        static const struct option longOptions[] = {
            {"help", no_argument, nullptr, 'h'},
            {"config", required_argument, nullptr, 'c'},
            { NULL, no_argument, nullptr, 0}};

        std::string cmd("");
        for (int i = 0; i < argc; ++i) {
            cmd += argv[i];
            cmd += " ";
        }

        do {
            int opt = getopt_long(argc, argv, shortOptions.c_str(), longOptions, &optionsIndex);
            if (opt == -1) {
                break; 
            }

            switch (opt) {
            case 'c':
                std::cout << std::string(optarg) << std::endl;
                m_configJsonPath.push_back(std::string(optarg));
                for (int i = optind; i < argc; i++) {
                    if (*argv[i] != '-') {
                        m_configJsonPath.push_back(std::string(argv[i]));
                    } 
                    else {
                        break;
                    }
                }
                break;
            case 'h':
                Usage();
                exit(0);
            default:
                Usage();
                exit(0);
            }
        } while (true);
    }

private:
    std::vector<std::string> m_configJsonPath;
};

} // namespace util

} // namespace sct

#endif
