#include <iostream>
using namespace std;

class Stu
{
  private:
    /**
     * 静态成员受访问修饰符的限制
     * 要解除该限制可使用友元函数
     */
    static int i;
    void fun()
    {
        cout << "friend function i = " << i << endl;
    }

    friend int main();

  public:
    /**
     * 静态数据成员需放在类外初始化，不能直接初始化
     * 只有常量静态的int, long, long long, char的数据成员才可以在类中初始化
     * 但可在类内任意位置进行赋值
     */
    static int a;

    static const int b = 66;

    int c = 0;

    Stu()
    {
        a = 15;
    }

    /**
     * 静态成员函数(无this指针)
     * 静态成员函数只能调用静态成员变量，但不可调用普通成员变量
     */
    static void show()
    {
        a = 100;
        //c = 10;
        cout << "i am a static funtion" << endl;
    }
};

/**
 * 静态成员类外初始化(此时不能加static)
 * 这里不是赋值
 */

int Stu::a = 10;
int Stu::i = 50;

int main()
{

    //类名作用域调用静态变量
    cout << "Stu::a = " << Stu::a << endl;
    //类名作用域调用静态函数
    Stu::show();

    cout << "-------" << endl;

    Stu s;
    //对象调用静态变量
    cout << "s.a = " << s.a << endl;
    //对象调用静态函数
    s.show();

    //不能直接访问私有静态成员i
    //cout << s.i << endl;
    //友元函数
    s.fun();

    system("pause");
    return 0;
}