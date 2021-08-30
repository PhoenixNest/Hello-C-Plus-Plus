#include <iostream>
using namespace std;

class outSide
{
  public:
    int o;
    outSide() : inside(this)
    {
        o = 10;
    }

    class inSide
    {
      public:
        int i;
        /**
         * 若在类外对外部类的成员进行修改是无法影响内部类中对外部类的调用的
         * 此时可以定义一个外部类的指针，并在内部类的构造函数的参数列表对该指针进行赋值
         * 将内部类的this指针传递给外部类，通知外部类对内部类的成员进行修改
         */
        outSide *os;
        inSide(outSide *os_pointer) : os(os_pointer)
        {
            i = 20;
        }

        void fun()
        {
            cout << os->o << endl;
        }
    };

  public:
    //要通过外部类调用内部类必须先声明内部类对象
    inSide inside;
};

int main()
{
    outSide o;
    //通过外部类的对象调用先前已在外部类中声明的内部类对象，对内部类的成员进行操作
    o.o = 100;
    o.inside.fun();

    system("pause");
    return 0;
}