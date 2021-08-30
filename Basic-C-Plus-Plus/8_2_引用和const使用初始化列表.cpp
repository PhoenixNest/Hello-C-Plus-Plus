#include <iostream>
using namespace std;

class Stu
{
  public:
    int a;
    int &b;
    const int d;

    //const修饰的成员需在初始化列表中赋值
    Stu(int c) : b(a), a(c), d(100)
    {
        cout << a << "---" << b << "---" << d << endl;
    }

    Stu(int c, int e) : b(a), a(c), d(e)
    {
        cout << a << "---" << b << "---" << d << endl;
    }

    // void fun()
    // {
    //     cout << a << "---" << b << "---" << d << endl;
    // }
};

int main()
{
    // int i = 15;
    // Stu s(i);

    Stu s(15);
    //s.fun();

    Stu s1(10, 100);
    //s1.fun();

    system("pause");
    return 0;
}