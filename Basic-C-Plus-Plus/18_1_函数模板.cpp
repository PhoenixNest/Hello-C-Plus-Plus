#include <iostream>
using namespace std;

// void fun(int a)
// {
//     cout << a << endl;
// }

// void fun(double b)
// {
//     cout << b << endl;
// }

/**
 * 函数模板(与Java的封装类似，类似泛型，实则是对函数重载的封装)
 * 写法：
 * 1.template<typename 模板名称>
 * 2.template<class 模板名称>
 * 
 * template 声明函数模板 <typename 模板名称> 尖括号中类似变量的初始化
 * 参数列表可包括多种参数，每个参数的类型可由传入参数决定
 * 使用函数模板后会动态识别参数列表中的参数并匹配
 * 函数模板只对接下来的代码块有效
 */
template <typename T>
void fun(T t)
{
    cout << t << endl;
}

template <typename X, typename Y>
void fun(X a, Y b)
{
    cout << a << "---" << b << endl;
}

int main()
{
    fun(10);
    fun(10, 10.01);

    system("pause");
    return 0;
}