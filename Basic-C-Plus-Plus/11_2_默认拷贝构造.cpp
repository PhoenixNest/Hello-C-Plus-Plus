#include <iostream>
using namespace std;

class Stu
{
  public:
    int a;
    char b[4];

    Stu()
    {
        a = 10;

        //字符类型数据的赋值
        b[0] = 'a';
        b[1] = 'b';
        b[2] = 'c';
        //strcpy_s(b, 4, "abc");
    }

    /**
     * 默认的拷贝构造也叫浅拷贝
     * 拷贝构造会复制原生构造函数中的成员(静态成员变量除外)
     * 如果人为定义一个拷贝构造，系统则不会进入默认拷贝构造，而是进入人为定义的拷贝构造
     */
    // Stu(Stu &stu)
    // {
    //     this->a = stu.a;
    //     strcpy_s(this->b, 4, stu.b)
    // }
};

int main()
{

    Stu s;
    cout << s.a << "-----" << s.b << endl;

    Stu s1 = s;
    cout << s1.a << "-----" << s1.b << endl;

    system("pause");
    return 0;
}