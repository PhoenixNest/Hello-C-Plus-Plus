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

    int operator>=(Stu &s1)
    {
        return (age >= s1.age);
    }

    int operator&(Stu &s1)
    {
        return (age & s1.age);
    }

    int operator&&(Stu &s2)
    {
        return (age && s2.age);
    }
};

// int operator>=(Stu &s1, Stu &s2)
// {
//     return (s1.age >= s2.age);
// }

//位的与运算(将数值转换为二进制后进行与运算)
// int operator&(Stu &s1, Stu &s2)
// {
//     return (s1.age & s2.age);
// }

//数值的与运算(例：两个不为0的数的&&运算为1)
// int operator&&(Stu &s1, Stu &s2)
// {
//     return (s1.age && s2.age);
// }

int main()
{
    Stu s1(10);
    Stu s2(20);

    cout << (s1 >= s2) << endl;
    cout << (s1 & s2) << endl;
    cout << (s1 && s2) << endl;

    system("pause");
    return 0;
}