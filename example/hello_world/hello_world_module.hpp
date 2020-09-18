#include <smt/smt.hpp>

class SampleModule : public smt::module::Module {
 public:
  bool Init() override;
  bool Run() override;
  bool Clear() override;

private:
  std::string str;
  int m_int_test;
  float m_float_test;
  bool m_bool_test;
  std::string m_string_test;    
};

REGIST_MODULE(SampleModule);
