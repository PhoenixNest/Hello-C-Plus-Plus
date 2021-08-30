#include <iostream>
using namespace std;

class Stu
{
  private:
    int a = 10;
    double b = 10.5;

  public:
    /**
     * 对象类型强制转换
     * 1.必须在类内使用
     * 2.不能声明返回值类型
     * 3.不建议经常使用
     * 4.若转换之后不影响原函数的值，建议加上const成为常函数
     */
    operator int() const
    {
        return a;
    }
    operator double() const
    {
        return b;
    }
};

int main()
{
    Stu s;
    cout << (int)s << endl;
    cout << (double)s << endl;

    system("pause");
    return 0;
}