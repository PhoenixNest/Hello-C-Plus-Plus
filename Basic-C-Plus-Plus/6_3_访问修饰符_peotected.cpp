#include <iostream>
using namespace std;

class People
{
  private:
    int a;

  protected:
    /**
   * protected对类外的函数和其他类不可见
   * 要使用protected的成员有两种方法：1.友元 2.继承
   * 只对类内和子类可见
   */
    void fun()
    {
        cout << "Function" << endl;
    }
};
/**
 * 继承
 * P1是People的子类
 * 子类声明 class 类名 : public 被继承的类名
 */
class P1 : public People
{
    void fun3()
    {
        fun();
    }
};

// class Test
// {
//     People p;
//     void fun2()
//     {
//         p.fun();
//     }

// }

int main()
{
    People p;
    //p.fun();

    system("pause");
    return 0;
}