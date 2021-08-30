#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    /**
     * 构造函数
     * 对象创建时自动调用，对数据进行初始化赋值，没有返回值
     * 类名(){}
     * 
     * new会触发构造函数
     * malloc不会触发构造函数
     */
    Stu()
    {
        age = 18;
    }
    void fun()
    {
        age = 15;
        cout << age << endl;
    }
};

int main()
{
    Stu s;
    //Stu *s1 = new Stu;
    s.fun();
    //s1->fun();

    system("pause");
    return 0;
}