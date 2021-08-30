#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    Stu()
    {
        age = 10;
    }

    /**
     * 类内运算符重载函数
     * 类内参数列表可无需写对象引用(省略了this指针，即默认最左边是类的对象)
     *                         类 + 基本数据类型
     * 原先写法1：int operator+(this->age, int i)
     *           {
     *              return (this->age + i)
     *           }
     * 原先写法2：int operator+(Stu &a, int i)
     *           {
     *              return (a.age + i);
     *           }
     */
    //优化写法
    int operator+(int i)
    {
        return (age + i);
    }

    //无法使用operator运算符重载的几种运算
    // 1.作用域运算符
    // operator ::()
    // {
    //
    // }

    // 2.取当成员是指针的时候，取指针对应空间的值的时候
    // operator.*()
    // {
    //
    // }

    // 3.三目运算符
    // operator?:()
    // {
    //
    // }
};

int main()
{
    Stu s;
    cout << (s + 10) << endl;

    system("pause");
    return 0;
}