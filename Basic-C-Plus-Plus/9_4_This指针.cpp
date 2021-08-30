#include <iostream>
using namespace std;

class Stu
{
  public:
    int a;
    Stu(int a)
    {
        /**
         * this是个指针！！！
         * this是个指针！！！
         * this是个指针！！！
         * 
         * this指针需先创建对象才会生成
         * this指针不是参数，是类成员函数的隐含参数
         * this指针的作用：
         * 1.区分同名
         * 2.是指向当前对象的指针(可通过指针访问成员)
         * 
         * 该处的this指针指向的a是类Stu中的变量a，而非传入的参数a
         * 该处将传入的参数a赋值给类Stu中的变量a
         * 
         * this指针也可调用类中的函数
         */
        this->a = a;
        this->fun();
    }

    void fun()
    {
        cout << a << endl;
    }

    Stu *GetAdd()
    {
        //返回类的地址
        return this;
    };
};

int main()
{
    Stu s(12);
    s.fun();

    Stu s1(15);

    //输出s的地址
    Stu *address = s.GetAdd();
    cout << address << endl;

    //输出s1的地址
    address = s1.GetAdd();
    cout << address << endl;

    //由于GetAdd是返回了类Stu的指针，故可以对类Stu中的成员进行操作(例如对成员变量进行赋值，调用类的函数 )
    address->fun();

    system("pause");
    return 0;
}