#include <iostream>
using namespace std;

/**
 * C++中的Struct结构体是类的一个特殊的类，类似于Java中的继承关系，结构体默认是公有的
 * 类中可以包括两种成员：1.数据成员，即声明变量或常量 2.函数成员
 * 类的最后不要忘记加上分号(;)结束
 */

class People
{
public: //访问修饰符，类似Java的私有类，公共类，保护类
  int i = 0;
  void fun()
  {
    cout << "Function"
         << "-" << i << endl;
  }
};

int main()
{

  /**
     * 类的初始化
     * 1.直接声明一个类的对象，此时不用new
     * 2.通过指针声明要使用的类的对象，此时和Java的new对象的思路一样(使用完后记得释放)
     */
  People p;
  People *p1 = new People;

  p.i = 10;
  p.fun();

  //指针变量调用成员变量 指针名 -> 调用的成员变量
  p1->i = 15;
  p1->fun();

  delete p1;

  system("pause");
  return 0;
}