#include <iostream>
using namespace std;
int main()
{
    /**
     * 这里的&不是取地址的意思，而是声明了a的一个引用a1，故a1是a的一个别名
     * 即a1 == a
     */
    int a = 10;
    int &a1 = a;

    cout << "a = " << a << endl;
    cout << "-----" << endl;
    /**
     * 对a1做改变同时也是对a做改变
     */
    a1 = 100;

    /**
    * 引用也可被引用
    * 即b == a1 == a
    */
    int &b = a1;

    cout << "a1 = " << a1 << endl;
    cout << "b = " << b << endl;
    cout << "-----" << endl;
    /**
     * 引用的地址都是一样的
     * 即a的地址 == a1的地址 == b的地址
     */
    cout << "a的地址:" << &a << endl;
    cout << "a1的地址:" << &a1 << endl;
    cout << "b的地址:" << &b << endl;
    cout << "-----" << endl;
    system("pause");
    return 0;
}