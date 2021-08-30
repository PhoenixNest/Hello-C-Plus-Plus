#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    float f;

    //构造函数可重载
    Stu()
    {
        age = 18;
        f = 0.5f;
    }

    //构造函数可以对参数进行预赋值
    Stu(int a, float b);
    // {
    //     age = a;
    //     f = b;
    // }
    int fun();
};

//类外声明构造函数(也叫函数原型)，要加作用域运算符声明作用域，此时不可以对参数进行预赋值
Stu::Stu(int a, float b)
{
    age = a;
    f = b;
}

//类外函数定义，要加作用域运算符声明作用域
int Stu::fun()
{
    cout << age << endl;
    return 0;
}

int main()
{
    //无参数的构造函数
    Stu s;
    cout << s.age << "\n"
         << s.f << endl;

    //带参数构造函数的对象声明，在声明对象后加(赋值的变量1，赋值的变量2，赋值的变量3 ...)
    Stu *s1 = new Stu(15, 2.5f);
    cout << s1->age << "\n"
         << s1->f << endl;

    system("pause");
    return 0;
}