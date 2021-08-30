#include <iostream>
using namespace std;

class Stu
{
  public:
    int a;
    int *b;

    //该处为构造函数
    Stu()
    {
        cout << "Start---构造函数" << endl;

        //申请了一个大小为10的int类型的指针空间
        b = new int(10);
    }

    Stu(int i)
    {
        cout << "Start---构造函数" << endl;
    }

    /**
     * 该处为析构函数(在程序块执行结束时自动调用)
     * ~类名()
     * 析构函数一般做空间的释放操作(delete)
     * 析构函数只能有一个，且不能带参数，不能重载
     * 析构函数系统会默认生成，默认生成的析构函数什么都不做
     * 
     * delete也会调用析构函数
     * free不会调用析构函数
     */
    ~Stu()
    {
        cout << "End---析构函数" << endl;
        delete b;
    }
};

int main()
{ //代码块开始执行，调用构造函数

    /**
     * 由于malloc返回的是一个void类型的指针，此时需要将其强制转换为Stu类的指针类型
     * C++中的malloc不会触发构造函数
     */
    Stu *s = (Stu *)malloc(sizeof(Stu));

    /**
     * C++中的free不会调用析构函数
     */
    free(s);

    // Stu s;
    // Stu *s = new Stu;
    // delete s; //类的指针对象只有遇到delete被释放后，才会调用析构函数

    //临时对象
    // Stu(1);

    system("pause");
    return 0; //代码块执行完毕，调用析构函数
}