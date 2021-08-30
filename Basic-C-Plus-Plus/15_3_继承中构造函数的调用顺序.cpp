#include <iostream>
using namespace std;

class Bean
{
  public:
    Bean()
    {
        cout << "Construct  Bean" << endl;
    }
};

class Test1 : public Bean
{
  public:
    Test1()
    {
        cout << "Construct Test1" << endl;
    }
};

class Test2 : public Test1
{
  public:
    Test2()
    {
        cout << "Construct Test2" << endl;
    }
};

int main()
{
    //继承中构造函数的调用顺序：先父类，后子类
    // Bean bean;
    // Test1 test1;
    Test2 test2;

    system("pause");
    return 0;
}