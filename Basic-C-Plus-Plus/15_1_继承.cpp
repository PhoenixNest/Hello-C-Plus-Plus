#include <iostream>
using namespace std;

//父类
class Study
{
public:
  void study()
  {
    cout << "study" << endl;
  }
};

//子类继承父类的格式(单继承)
class Man : public Study
{
public:
  void work()
  {
    cout << "work" << endl;
  }
};

//子类继承父类的格式(单继承)
class Children : public Study
{
public:
  void work()
  {
    cout << "go to school" << endl;
  }
};

int main()
{
  Man m1;
  Man *m2;
  //调用父类Study中的方法
  m1.study();
  m2->study();
  //调用自身方法
  m1.work();
  m2->work();

  Children c1;
  Children *c2;
  //调用父类Study中的方法
  c1.study();
  c2->study();
  //调用自身方法
  c1.work();
  c2->work();

  system("pause");
  return 0;
}