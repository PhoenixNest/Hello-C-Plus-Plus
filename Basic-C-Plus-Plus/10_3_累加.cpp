#include <iostream>
using namespace std;

class Stu
{
  public:
    static int i;

    /**
     * 由于对象创建时会自动调用构造函数，故每创建一个对象时都会使i自加1
     * 假设要使i自加到5，就创建5个对象(也可创建一个数量为5的对象数组)，就会调用5次构造函数，使得i每次都自加1
     * 从而达到不使用循环，得到累加的效果
     */
    Stu()
    {
        i++;
        cout << "i = " << i << endl;
    }
};

int Stu::i = 0;
int main()
{
    //对象数组
    Stu s[5];
    cout << Stu::i << endl;

    system("pause");
    return 0;
}