#include <iostream>
using namespace std;

class Stu
{
  private:
    int a;
    double b;
    int error_status;

  public:
    Stu()
    {
        a = 10;
        b = 5.5;
        error_status = -1;
    }

    /**
     * 该处返回了一个void类型的通用指针
     * 通用类型指针的大小的无法确定的，所以无法使用sizeof()输出大小
     * 任何类型的指针都可以转换为通用类型指针，此时的强制转换基本不会出错(其他类型的指针 --> void*)
     * 但当通用类型指针转换为其他类型的指针时可能会出错(void* --> 其他类型的指针)
     * 同类型的转换不会出现问题
     */
    void *operator[](int n)
    {
        switch (n)
        {
        case 0:
            //返回一个int的地址
            return &a;
        case 1:
            //返回一个double类型的地址
            return &b;
        }

        return &error_status;
    }
};

int main()
{
    Stu s;
    //该处将int类型的指针强制转换为通用类型void指针，并取出该地址对应的值
    cout << *(int *)s[0] << endl;

    //该处将double类型的指针强制转换为通用类型void指针，并取出该地址对应的值
    cout << *(double *)s[1] << endl;

    //赋值
    *(double *)s[1] = 66.66;
    cout << *(double *)s[1] << endl;
    
    system("pause");
    return 0;
}