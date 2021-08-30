#include <iostream>
using namespace std;

/**
 * 类模板
 * 写法与函数模板一样，且只对在模板定义下的类有效
 * 
 * 类模板可带默认值，并跟随在函数模板名后定义，只有类模板可带默认值
 * 例1：template <typename T = char> 该类模板的默认参数类型为char
 * 例2：template <typename X = int , typename Y = double>
 * 例3：template <typename X , typename Y = double>
 * 默认值的初始化的规则为从右向左指定
 * 有默认值的时候，类模板的对象初始化可以不传默认值，即：Father<> father(); 但必须有尖括号：<>
 */

//template <typename T = char>
template <typename X = int, typename Y = double>
class Father
{
  public:
    //可将变量的类型定义为类模板的值，达到在类初始化的时候，通过构造函数为成员变量赋值
    X x;
    Y y;
    // Father(T t )
    // {
    //     a = t;
    // }

    Father(X input_x, Y input_y)
    {
        x = input_x;
        y = input_y;
    }

    void show()
    {
        cout << x << "---" << y << endl;
    }
};

//类外声明类模板中的函数 方法1
// void Father<int, double>::show()
// {
//     cout << x << "---" << endl;
// }

//类外声明类模板中的函数 方法2
// template <typename X, typename Y>
// void Father<int, double>::show()
// {
//     cout << x << "---" << y << endl;
// }

int main()
{
    /**
     * 类模板的对象初始化
     * 尖括号中的值即类模板中T的类型
     * 由于Father类重写了构造函数，故在初始化时需要匹配模板参数列表
     */
    //Father<int> father(10);
    //Father<char> father('A');
    //father.show();

    /**
     * 类模板的指针对象初始化
     * 类模板的参数列表需与模板的参数列表一一对应
     * 指针对象初始化中的构造函数的初始化跟在尖括号后
     */
    Father<int, double> *f = new Father<int, double>(10, 100.001);
    // f->x = 10;
    // f->y = 20;
    f->show();

    system("pause");
    return 0;
}