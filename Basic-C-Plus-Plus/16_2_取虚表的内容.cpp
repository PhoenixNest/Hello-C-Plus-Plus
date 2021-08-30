#include <iostream>
using namespace std;

class Father
{
  public:
    virtual void fun()
    {
        cout << "Father_fun" << endl;
    }

    // virtual void show()
    // {
    //     cout << "Father_show" << endl;
    // }
};

class Son : public Father
{

  public:
    virtual void fun()
    {
        cout << "Son" << endl;
    }
    virtual void show()
    {
        cout << "Son_show" << endl;
    }
};

int main()
{
    Father *father = new Son();
    father->fun();

    //64位编译器的整形为8字节
    cout << sizeof(father) << endl;

    typedef void (*p)();

    //*(int *)father 虚表的地址
    //(int *)*()int *father 获得虚表的整形指针数组地址的首元素
    //((p)(*((int *)*(int *)father + 0)))() 获得虚表的整形指针数组地址的首元素(该处的首元素为函数地址)并转换为函数对象
    ((p)(*((int *)*(int *)father + 0)))(); // 得到fun函数的地址
    ((p)(*((int *)*(int *)father + 1)))(); // 得到show函数的地址

    int *final_p = (int *)*((int *)*(int *)father + 2);

    system("pause");
    return 0;
}