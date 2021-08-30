#include <iostream>
using namespace std;

struct struct_Stu
{
    int b;
    float c;
};

class Stu
{
  public:
    int a[4];

    struct_Stu s;

    Stu(struct_Stu st_S) : s(st_S) // : a()
    {
        //for循环给数组赋值
        for (int i = 0; i < 4; i++)
        {
            a[i] = 0;
        }

        //memset(数组的首地址，赋的值，数组的字节长度)数组初始化函数，注意不要越界
        //memset(a, 0, 16);
    }

    // void fun()
    // {
    //     for (int i = 0; i < 4; i++)
    //     {
    //         cout << a[i] << endl;
    //     }
    // }
};

int main()
{
    struct_Stu s_S_input = {1080, 150.5f};

    // Stu s;
    // s.fun();

    Stu s(s_S_input);
    //s.fun();

    // struct_Stu s1 = {10, 15.5f};
    // struct_Stu s2 = s1;
    // cout << s2.b << s2.c << endl;

    system("pause");
    return 0;
}