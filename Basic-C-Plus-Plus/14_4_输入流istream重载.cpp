#include <iostream>
using namespace std;

class Stu
{
  private:
    int age;
    double score;

  public:
    Stu()
    {
        age = 0;
        score = 0.0;
    }

    void fun()
    {
        cout << age << endl;
        cout << score << endl;
    }

    //声明为友元函数
    friend istream &operator>>(istream &is, Stu &s);
};

/**
 * 输入流的运算符重载
 * 返回值为一个istream输入流
 * 括号中的第一个参数代表一般的输入语句中的cin，即istream的引用
 *         第二个参数代表对象的引用
 * 由于该函数的参数列表的第一个参数必须是istream的引用，故该函数不能在类内使用
 * 
 * 需要判断输入是否出现问题
 */
istream &operator>>(istream &is, Stu &s)
{
    is >> s.age >> s.score;
    if (is.fail())
    {
        //当输入错误内容时，一般会将数值初始化为输入前的值，即可再次进行输入
        s.age = 0;
        s.score = 0.0;
        //cout << "Fail" << endl;
    }
    else
    {
        return is;
    }
}

int main()
{
    Stu s1;

    //即cin >> s1运算完毕后会成为一个新的istream(可以理解成一个新的cin)
    cin >> s1;
    s1.fun();

    system("pause");
    return 0;
}