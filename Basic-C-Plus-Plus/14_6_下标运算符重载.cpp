#include <iostream>
using namespace std;

class Stu
{
  private:
    int a;
    int b;
    int c;
    double d;
    int error_status;

  public:
    Stu()
    {
        a = 10;
        b = 20;
        c = 30;
        error_status = -1;
    }

    /**
     * []下标运算符
     * 当一个类的对象进行下标运算时会调用此函数(可以理解为将一个类的对象变成一个数组，类内的数据即是数组的元素)
     * 例：s是类Stu的一个对象，若s[1]，此时的参数列表中的n就等于1，即为类Stu中的第2个参数b赋值
     */
    int &operator[](int n)
    {
        switch (n)
        {
        case 0:
            return a;
        case 1:
            return b;
        case 2:
            return c;
        }

        return error_status;
    }
};

int main()
{
    Stu s;
    //该处为输出类的中的第3个参数c的值
    cout << s[2] << endl;

    //该处为类中的第1个参数a赋值为100，并输出该数
    s[0] = 100;
    cout << s[0] << endl;

    system("pause");
    return 0;
}