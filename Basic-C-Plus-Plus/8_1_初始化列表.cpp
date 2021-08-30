#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    float f;
    /**
     * 成员初始化的顺序只与声明的顺序(从上向下)有关，与与赋值的顺序无关
     * 在构造函数后加 : 变量(值),变量(值)...即给成员变量初始化(初始化列表)
     * 成员之间可以相互赋值，但必须遵循从上向下赋值的规则
     */

    // Stu() : age(10), f(1.5f)
    // {
    //     age = 18;
    // }

    Stu() : f(age), age(20)
    {
        //age = 18;
    }

    void fun()
    {
        cout << age << "---" << f << endl; 
    }
};

int main()
{
    Stu s;
    s.fun();

    system("pause");
    return 0;
}