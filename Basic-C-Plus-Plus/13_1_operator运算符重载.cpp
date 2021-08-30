#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    double score;

    Stu()
    {
        age = 18;
        score = 90.5;
    }
};
/**
 * 运算符重载函数：
 * 当一个类的对象和一个基本数据类型进行运算时，会调用运算符重载函数
 * 其中涉及类的运算时，运算符重载函数的参数要使用类的对象引用
 * 运算符重载可进行多种运算：加减乘除等等运算，只需修改operator后面的相应运算符即可
 * 运算符重载函数不适用于基本数据类型运算
 * 
 * 写法：
 * 返回值类型 operator+(具体参数)
 */
void operator+(Stu &a, int b)
{
    cout << (a.age + b) << endl;
}

void operator-(int a, Stu &b)
{
    cout << (a - b.score) << endl;
}

int main()
{
    int i = 100;

    Stu s1;
    //调用operator+(Stu &a, int b)
    s1 + i;

    Stu s2;
    //调用operator-(int a, Stu &b)
    i - s2;

    system("pause");
    return 0;
}