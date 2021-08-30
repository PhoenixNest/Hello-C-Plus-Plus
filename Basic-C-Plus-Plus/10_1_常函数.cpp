#include <iostream>
using namespace std;

class Stu
{
  public:
    /**
   * 常函数：
   * 
   * 常函数的声明
   * 在函数的括号后面加const
   * 
   * 构造函数和析构函数不能做常函数
   */
    int a;

    Stu()
    {
        a = 15;
    }

    void show() const //常函数的this指针是 函数名 *指针名 const
    {
        /**
         * 可以使用数据成员
         * 但不能修改数据成员
         * 
         * 在常函数中定义的变量可以修改数据
         */
        //a = 13;//不能修改数据成员
        //this->a = 13;//不能修改数据成员
        int b = 2;
        b = a * b;

        cout << "i am show" << endl;
        cout << a << endl;
        cout << b << endl;
    }

    void fun() //普通函数
    {
        cout << "i am fun" << endl;
    }
};

int main()
{
    //Stu s;
    const Stu s; //常对象，只能调用常函数，不能调用普通函数
    //s.fun();//不能调用普通函数
    s.show();

    system("pause");
    return 0;
}