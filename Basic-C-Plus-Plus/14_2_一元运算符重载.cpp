#include <iostream>
using namespace std;

class Stu
{
  public:
    int age;
    Stu(int a)
    {
        age = a;
    }

    int operator-()
    {
        return -age;
    }

    int operator!()
    {
        return (!age);
    }
};

//将数值进行负运算
// int operator-(Stu &s1)
// {
//     return -(s1.age);
// }

//取非运算符(例：一个不为0的数进行取非会得到1，一个为0的数取非会得到1)
// int operator!(Stu &s1)
// {
//     return (!s1.age);
// }

int main()
{
    Stu s1(10);
    cout << (-s1.age) << endl;
    cout << (!s1.age) << endl;

    system("pause");
    return 0;
}