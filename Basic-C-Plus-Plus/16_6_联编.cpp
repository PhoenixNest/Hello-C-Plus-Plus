#include <iostream>
using namespace std;

/**
 * 联编是程序执行时将函数实现和函数调用关联的一个过程，分为：
 *      1.静态联编
 *      2.动态联编针对于多态
 */ 
class Father
{
  public:
    virtual void fun()
    {
        cout << "Father" << endl;
    }
};

class Son : public Father
{
  public:
    void fun()
    {
        cout << "Son" << endl;
    }
};

int main()
{
    Father *father;

    int i;
    cin >> i;
    switch (i)
    {
    case 1:
        father = new Father();
        break;
    case 2:
        father = new Son();
        break;
    }

    father->fun();

    system("pause");
    return 0;
}