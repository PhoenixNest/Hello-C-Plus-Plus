#include <iostream>
using namespace std;
int main()
{
    /**
     * 常量(比如字符常量，数值(整型，浮点型)常量)的引用
     * 常量标识符：const，一旦标识就不可修改，类似于Java的final
     * 这里引用a = 10
     * 即a = 10
     */
    const int &a = 10;
    cout << "常量引用a = " << a << endl;

    /**
     * 一维数组的引用
     * 该处的引用p即p == 数组arr
     * p已成为一个数组，且长度和元素和arr一样，对p做修改即是对arr做修改
     */
    int arr1[10];
    int(&p)[10] = arr1;

    p[0] = 10;
    cout << arr1[0] << endl;

    /**
     * 二维数组的引用
     * 类型一定要匹配
     */
    int arr2[2][3];
    int(&p2)[2][3] = arr2;

    p2[0][1] = 10;
    cout << arr2[0][1] << endl;

    /**
     * 指针的引用
     * 该处的指针point指向了b的地址，故*point取出来的b的值等同于b
     * 引用指针p3指向了point，故现在引用指针p3取出来的值等于*point的值
     * 即b == *point == *p3
     */
    int b = 10;
    int *point = &b;
    int *&p3 = point;

    *p3 = 120;

    cout << "指针point所指向的b的值为：" << *point << endl;
    cout << "引用指针p3指向的point的值为：" << *p3 << endl;

    system("pause");
    return 0;
}