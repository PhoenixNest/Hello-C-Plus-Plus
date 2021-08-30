#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    double score;

    Stu()
    {
        age = 10;
        score = 10.5;
    }
};

//带返回值的运算符重载函数
int operator+(Stu &a, int b)
{
    return (a.age + b);
}

//带返回值的运算符重载函数
int operator-(int a, Stu &b)
{
    return (a - b.age);
}

Stu &operator+(Stu &a, Stu &b)
{
    //a.age = a.age + b.age
    a.age += b.age;
    return a;
}

int main()
{
    Stu s1, s2;
    //先调用一次int operator+(Stu &a, int b)得到s1 + 10的值20，再得到20 + 50 = 70
    //       [(s1 + 10) + 50]
    cout << (s1 + 10 + 50) << endl;

    //先调用一次int operator+(Stu &a, int b)得到s1 + 20的值30，再得到30 + 30 = 60，最后调用int operator-(int a, Stu &b)得到60 - s2 = 50
    //      {[(s1 + 20) + 30] - s2}
    cout << (s1 + 20 + 30 - s2) << endl;

    //调用Stu &operator+(Stu &a, Stu &b)，对象与对象相加的时候要多添加一个括号
    //      [(s1 + s2) + 20]
    cout << ((s1 + s2)) + 20 << endl;

    system("pause");
    return 0;
}