#include <iostream>
using namespace std;

/**
 * 该函数的参数引用a1在主函数中被调用
 * 故在主函数中对函数fun1传入参数的同时，也把传入的实际参数b和引用参数a1关联了起来
 * 即a1 == b，a1和b共享一块地址空间
 * 但此时对a1做修改也就是对b做修改(这里要和函数传入的参数做对比)
 */
void fun1(int &a1)
{
    /**
     * 通过函数fun1修改b1的值
     */
    //a1 = 15;
    cout << "fun1：" << a1 << endl;
}

/**
 * 区分引用参数与普通参数
 * 传入一个普通参数b1
 * 即把b1的值赋给了a2，但此时的a2和b的地址空间是各自独立的，而非共享
 */
void fun2(int a2)
{
    cout << "fun2：" << a2 << endl;
}

/**
 * 引用指针做参数
 * 传入的&b(b的地址)并将其赋值给指针p
 * 此时p指向了b的地址，并将b的值覆盖为25
 */
void fun3(int *p)
{
    *p = 25;
    cout << "fun3：" << *p << endl;
}

int main()
{
    int b = 10;
    fun1(b);
    //cout << "b1 = " <<b1<< endl;

    fun2(b);

    fun3(&b);

    system("pause");
    return 0;
}