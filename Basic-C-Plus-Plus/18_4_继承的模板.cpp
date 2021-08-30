#include <iostream>
using namespace std;

template <typename X, typename Y>
class Father
{
public:
  X x;
  Y y;

  Father()
  {
    x = 10;
    y = 20.02;
  }

  // Father(X input_x, Y input_y)
  // {
  //   x = input_x;
  //   y = input_y;
  // }

  void fun()
  {
    cout << x << "---" << y << endl;
  }
};

//类模板的继承(指定父类中模板的类型)
// class Son : public Father<int, double>
// {
// public:
//   //无参构造的类模板继承
//   Son() : Father()
//   {
//   }

//   //有参构造的类模板继承，该处的模板类型可加可不加
//   // Son() : Father<int>(10)
//   // {
//   // }
// };

//类模板的继承(通过子类的参数列表，动态指定父类中模板的类型)
template <typename A, typename B>
class Son : public Father<A, B>
{
public:
  //无参构造的类模板继承
  Son() : Father<A, B>()
  {
  }

  //有参构造的类模板继承，该处的模板类型可加可不加
  // Son() : Father<int>(10)
  // {
  // }
};

int main()
{
  // 子类继承父类的指定类型的类模板后，无需再次声明参数列表
  // Son son;

  //动态指派父类中的类模板的类型
  Son<long, double> son;
  son.fun();

  system("pause");
  return 0;
}