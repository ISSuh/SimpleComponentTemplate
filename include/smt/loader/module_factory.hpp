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

#ifndef SMT_LOADER_MODULE_FACTORY
#define SMT_LOADER_MODULE_FACTORY

#include <map>
#include <memory>

#include <smt/base/handle.hpp>
#include <smt/loader/module_loader.hpp>

namespace smt{

namespace loader{

class AbstractModuleFactoryBase{
public:
    AbstractModuleFactoryBase(const std::string& className,
                             const std::string& baseClassName)
        : m_baseClassName(baseClassName), m_className(className) {}

    virtual ~AbstractModuleFactoryBase();

    const std::string GetBaseClassName() const{
        return m_baseClassName;
    };

    const std::string GetClassName() const{
        return m_className;
    };

protected:
    std::string m_baseClassName;
    std::string m_className;
};

template <typename Base>
class AbstractModlueFactory : public AbstractModuleFactoryBase{
public:
    AbstractModlueFactory(const std::string& className,
                          const std::string& baseClassName)
        : AbstractModuleFactoryBase(className, baseClassName) {}

    virtual Base *CreateObj() const = 0;

private:
    AbstractModlueFactory();
    AbstractModlueFactory(const AbstractModlueFactory &);
    AbstractModlueFactory &operator=(const AbstractModlueFactory &);
};

template <typename ModuleObject, typename Base>
class ModuleFactory : AbstractModlueFactory<Base>{
public:
    ModuleFactory(const std::string& className,
                  const std::string& baseClassName)
        : AbstractModlueFactory<Base>(className, baseClassName) {}

    Base *CreateObj() const { 
        return new ModuleObject; 
    }
};

} // namespace loader

} // namespace smt

#endif