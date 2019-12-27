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
#include <memory>
#include <smt/smt.hpp>

using Handle = smt::base::Handle;

int main(int argc, char **argv){
    smt::util::ArgParser argPaser;
    argPaser.ParseArguments(argc, argv);

    Handle *h = Handle::GetInstence(argPaser.GetParsedJson());
    h->Init();

    smt::controller::ModuleController controller(*h);
    controller.Init();

    h->WaitForModule(100);
    
    controller.Clear();

    h->Shutdown();
}