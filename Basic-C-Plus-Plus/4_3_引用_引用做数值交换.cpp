#include <iostream>
using namespace std;

/**
 * 传入普通参数由于传入的传入的i1，j1与形式参数a，b的空间是彼此共享的
 * 即此时的a == i1，b == j1
 * 故对a和b进行交换操作既是对i1和j1进行交换操作
 * -----
 * 交换完成
 */
void Exchange1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 传入普通参数时由于传入的i2，j2与形式参数a，b都是各自的独立空间
 * 故即使对a和b进行交换操作也不会对i2与j2的值造成影响
 * -----
 * 无法交换
 */
void Exchange2(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 传入地址时由于传入的&i3与&j3与形式参数指针a和指针b同时指向了彼此的空间
 * 故此时指针a指向了i3的地址，指针b指向了j3的地址，对指针a和指针b的值做出的改变也会对i3与j3造成影响
 * 即 a == &i3，b == &j3
 *    *a == i3，*b == j3
 * -----
 * 交换完成
 */
void Exchange3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int i1 = 10, j1 = 20;

    cout << "交换前的i1 = " << i1 << endl;
    cout << "交换前的j1 = " << j1 << endl;
    cout << "-----" << endl;

    Exchange1(i1, j1);
    cout << "交换后(引用参数)的i = " << i1 << endl;
    cout << "交换后(引用参数)的j = " << j1 << endl;
    cout << "-----" << endl;
    cout << "------------" << endl;

    int i2 = 10, j2 = 20;
    cout << "交换前的i2 = " << i2 << endl;
    cout << "交换前的j2 = " << j2 << endl;
    cout << "-----" << endl;

    Exchange2(i2, j2);
    cout << "交换后(普通参数)的i = " << i2 << endl;
    cout << "交换后(普通参数)的j = " << j2 << endl;
    cout << "-----" << endl;
    cout << "------------" << endl;

    int i3 = 10, j3 = 20;
    cout << "交换前的i3 = " << i3 << endl;
    cout << "交换前的j3 = " << j3 << endl;
    cout << "-----" << endl;

    //传入地址
    Exchange3(&i3, &j3);
    cout << "交换后(指针)的i3 = " << i3 << endl;
    cout << "交换后(指针)的j3 = " << j3 << endl;
    cout << "-----" << endl;

    system("pause");
    return 0;
}