#include <iostream>
using namespace std;

class Stu
{
  private:
    int age;

  public:
    Stu()
    {
        age = 12;
    }

    //声明为友元函数
    friend ostream &operator<<(ostream &os, const Stu &s);
};

/**
 * 输出流的运算符重载
 * 返回值为一个ostream输出流
 * 括号中的第一个参数代表一般的输出语句中的cout，即ostream的引用
 *         第二个参数代表对象的const常引用
 * 由于该函数的参数列表的第一个参数必须是ostream的引用，故该函数不能在类内使用
 */
ostream &operator<<(ostream &os, const Stu &s)
{
    os << s.age << endl;
    return os;
}

int main()
{
    Stu s1;
    //即cout << s1运算完毕后会成为一个新的ostream(可以理解成一个新的cout)
    cout << s1 << s1 << endl;

    system("pause");
    return 0;
}