#include <iostream>
using namespace std;

/**
 * 可以声明多个友元，提高了程序的效率，但友元破坏了类的封装性，不是迫不得已尽量不要使用
 * 友元针对1.private私有的类 2.protected被保护的类
 * 当函数被声明为某个类的友元函数时，即可调用该类中的私有成员
 * 
 * 友元函数的声明：
 * 1.声明友元函数：friend 返回值类型 函数名();
 * 2.声明友元类：friend class 类目;
 */
class Stu
{
  private:
    //protected:
    int age;
    void fun()
    {
        age = 10;
        cout << age << endl;
    }

  public:
    //接口函数也可以调用私有成员
    int getage()
    {
        return age;
    }

    int setage()
    {
        age = 15;
    }
    friend void fun1();
    friend int main();

  protected:
    friend class Teacher;
};

class Teacher
{
  public:
    Stu s2;
    void fun2()
    {
        s2.fun();
    }
};

void fun1()
{
    Stu s;
    s.fun();
}

int main()
{
    //友元函数main()的调用
    Stu s1;
    s1.fun();
    s1.setage();
    int a = s1.getage();
    cout << "setget = " << a << endl;

    //友元函数fun1()的调用
    fun1();

    //友元类Teacher的调用
    Teacher t;
    t.fun2();

    system("pause");
    return 0;
}