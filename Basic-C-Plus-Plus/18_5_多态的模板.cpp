#include <iostream>
using namespace std;

template <typename X, typename Y>
class Father
{
public:
  // X x;
  // Y y;

  // Father(X input_x, Y input_y)
  // {
  //     x = input_x;
  //     y = input_y;
  // }

  virtual void fun()
  {
    cout << "Father" << endl;
  }
};

template <typename A, typename B>
// template <typename A, typename B, typename, C>
class Son : public Father<A, B>
{
public:
  // Son() : Father<A, B>()
  // {
  // }

  void fun()
  {
    cout << "Son" << endl;
  }
};

int main()
{
  /**
   * 多态的模板对象初始化中，父类和子类的参数列表需根据情况指派类型的数量，且父类的函数列表必须和子类中的相通(一一对应)
   * 当子类没有指定类模板的时候，子类的参数列表无需加上模板参数列表
   * 例：Father<short, long> *father = new Son<short, long, double>
   */
  Father<int, double> *father = new Son<int, double>;
  father->fun();

  system("pause");
  return 0;
}