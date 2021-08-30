#include <iostream>
using namespace std;

class Father
{
  public:
    int a;
    virtual void fun()
    {
    }
};

class Son : public Father
{
  public:
    int b;
    void fun()
    {
    }
};

int main()
{
    Father *father;
    Son *son;
    /**
     * dynamic_cast<type>(profresion)
     * 当type和profresion为派生类(子类指针转父类指针)或自己转自己时才合法
     * 当父类指针转子类指针时，父类必须为多态(父类存在虚函数，且子类重写了该虚函数)才可以进行合法转换
     */
    father = dynamic_cast<Father *>(son);
    //son = dynamic_cast<Son *>(father);

    system("pause");
    return 0;
}