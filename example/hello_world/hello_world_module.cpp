#include "hello_world_module.hpp"

bool SampleModule::Init() {
    str = "Hello World!";
    // GetParam("int_test", m_int_test);
    // GetParam("float_test", m_float_test);
    // GetParam("bool_test", m_bool_test);
    // GetParam("string_test", m_string_test);

    return true;
}

bool SampleModule::Run() {
    std::cout << str << '\n';

    return true;
}

bool SampleModule::Clear() {
    return true;
}