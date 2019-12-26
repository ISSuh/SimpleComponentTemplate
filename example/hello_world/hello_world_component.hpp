#include <iostream>
#include <smt/smt.hpp>

class SampleModule : public smt::module::Module{
public:
    bool Init() override {
        str = "Hello World!";
        GetParam("int_test", m_int_test);
        GetParam("float_test", m_float_test);
        GetParam("bool_test", m_bool_test);
        GetParam("string_test", m_string_test);

        return true;
    }

    bool Run() override {
        std::cout << str << '\n';

        return true;
    }

    bool Clear() override {
        return true;
    }

private:
    std::string str;
    int m_int_test;
    float m_float_test;
    bool m_bool_test;
    std::string m_string_test;    
};

