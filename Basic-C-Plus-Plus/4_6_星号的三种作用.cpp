#include <iostream>
using namespace std;
int main()
{
    /**
     *  第一种作用：在声明变量的时候* 指针变量
     */
    int *p = NULL;
    //int *i[5]; 声明一个包含5个指针变量的数组

    int i = 1;
    //这里把变量i的地址赋给了指针p1 "&"取地址符号
    int *p1 = &i;

    /**
     * 第二种作用：地址操作符
     * 这里要与声明指针区分开来
     * 由于上面已经把i的地址(&i)赋给了指针p1，所以这里的*p1为地址操作，取出了i的值
     */
    //读取
    cout << *p1 << endl;

    //写入，这里为i赋值
    *p1 = 100;
    cout << i << endl;

    //第三种作用：乘法运算
    int c = 12 * 5;
    cout << c << endl;

    system("pause");
    return 0;
}