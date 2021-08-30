#include <iostream>
using namespace std;

class Stu
{
  public:
    Stu()
    {
        cout << "Orign" << endl;
    }

    /**
     * 拷贝构造
     * 写法和构造函数大体相同，参数位置为类的常(const)引用
     * 
     * 和构造函数一样，在类创建的时候调用，和构造函数是重载关系
     */
    Stu(const Stu &a)
    {
        cout << "Copy" << endl;
    }
};

void fun(Stu stu)
{
}

Stu fun()
{
    //返回一个类的临时对象，用a给临时对象赋值，此时也会调用拷贝构造
    Stu a;
    //在此时做返回值调用拷贝构造(但该编译器不会调用拷贝构造，可能是编译器的问题？？？)
    return a;
}

int main()
{
    Stu s1;

    // 当对象将另一个已有对象作为参数传递时会调用拷贝构造，而不会调用原始的构造函数(6钟写法)
    // Stu s2(s1);            //通过类对象的参数传递
    // Stu s2 = s1;           //通过初始化
    // Stu s2 = Stu(s1);      //通过临时对象的参数(和Stu fun()的作用一样，都会调用拷贝构造)(较少见)
    // Stu *s2 = new Stu(s1); //指针对象(数组的话不能这么赋值)

    // 拷贝构造无法通过赋值实现
    // Stu s2;
    // s1 = s2;

    // 拷贝构造可作为函数的参数传递进行调用
    // fun(s1);

    // 调用返回值为类对象的函数fun()
    // fun();

    // 直接通过临时对象的一个新的参数调用拷贝构造(但此时不会调用拷贝构造，可能是编译器的问题？？？)
    // Stu(s2);

    system("pause");
    return 0;
}