#include <iostream>
using namespace std;

int &fun()
{
    int a = 10;
    return a;
}

int main()
{
    /**
     * 此时的引用b == 返回值a
     * 即对b做的改变就是对返回值a做改变
     * -----
     * 由于fun中的局部变量a在返回的时候会释放空间
     * 故此时的引用b实际上操作了非法空间，但b的值却还是和a相等
     * 这一点是不建议出现的，因为引用一块非法的地址所造成的后果是未知的
     */
    int &b = fun();
    cout << b << endl;
    system("pause");
    return 0;
}