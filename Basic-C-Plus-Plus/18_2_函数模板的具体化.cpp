#include <iostream>
using namespace std;

struct Struct_demo
{
    int a;
    double b;
};

void fun(int a)
{
    cout << a << endl;
}

template <typename T1>
void fun(T1 t)
{
    cout << t << endl;
}

template <>
void fun<int>(int i)
{
    cout << i << endl;
}
/**
 * 函数模板的具体化
 * 可解决当传入类或结构体时的系统参数判断问题
 * 会根据传入参数动态调整函数模板
 * 例：当传入参数为类或对象的时候，由于类或对象无法 输出，故系统报错
 * 
 * 函数模板的优先级顺序：
 * 具体化函数模板 > 普通函数模板
 * 
 * 与全局函数的优先级对比：
 * 普通函数 > 具体化函数模板 > 普通函数模板
 */
template <>
void fun<Struct_demo>(Struct_demo s)
{
    cout << s.a << "---" << s.b << endl;
}

int main()
{

    fun(10);

    Struct_demo s{10, 10.01};
    fun(s);

    system("pause");
    return 0;
}