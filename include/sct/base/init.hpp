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

#ifndef SCT_BASE_INIT
#define SCT_BASE_INIT

namespace sct {

namespace base {

// TODO : Implement Singleton Class
/**
 *  Handle Class
 *  
 *  Singleton Class
 *  Init argument & return argument for every user module
 *  Init schduler
 *  Wait for user module
 *  Clear & Shutdown all module 
 * 
 **/
class Handle(){
    virtual ~Init() {};

protected :
    Init(){

    };
};

} // namespace base

} // namespace sct

#endif
