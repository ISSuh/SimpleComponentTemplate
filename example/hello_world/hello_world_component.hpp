#include <iostream>
#include <sct/component/component.hpp>

class SampleComponent : public sct::component::Component{
public:
    bool Init() override {
        str = "Hello World!";

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
};

