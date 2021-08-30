#include <iostream>
using namespace std;

class Father
{
  public:
    /**
     * 纯虚函数(抽象类)
     * 变量和构造函数不能声明为虚函数
     * 一旦声明为纯虚函数，则不能实例化对象，必须由子类继承并重写抽象类中的方法后，才能实例化对象
     * 写法: virtual 返回值类型 函数名() = 0
     * 
     * 接口类：
     * 纯虚函数组成的类，不能含有任何非虚函数的成员变量或函数
     */
    virtual void fun() = 0;
};

class Son : public Father
{
  public:
    void fun()
    {
        cout << "Son_fun" << endl;
    }
};

int main()
{

    Son s;
    s.fun();
    system("pause");
    return 0;
}