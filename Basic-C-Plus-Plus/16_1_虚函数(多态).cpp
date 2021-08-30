#include <iostream>
using namespace std;

class Father
{
  public:
    /**
     * 虚函数定义:
     * 父类的指针，指向子类的空间
     * virtual 返回值类型 函数名
     * 1.子类中的函数必须和父类中的该函数同名
     * 2.多子类的时候，指向哪个子类的空间，就调用哪个子类
     * 
     * 被虚函数定义的函数，在被子类继承，且子类中有同名函数的时候，将略过父类的此函数
     * 当子类中无同名函数，父类仍保有虚函数的时候，会重新启用并调用父类中的虚函数
     */
    virtual void fun()
    {
        cout << "Father" << endl;
    }

    virtual void fun_plus()
    {
        cout << "Father fun_plus" << endl;
    }
};

class Son : public Father
{
  private:
    int son = 18;

  public:
    void fun()
    {
        cout << "Son" << endl;
    }
};

//与另一子类Son不同名，但同成员的子类
class Son_plus : public Father
{
  private:
    int son_plus = 18;

  public:
    void fun()
    {
        cout << "Son_plus" << endl;
    }
};

int main()
{
    /**
     * 同样代码的不同结果，同种调用的不同结果，也称为多态
     * 多态的使用范围仅限于指针对象
     * 父类的指针，指向子类的空间，父类指针只能调用父类本身的方法，无法调用子类的方法
     * 也可理解为，父类指针的多种执行状态，即多态
     */
    Father *father = new Son;
    Father *father_to_Sonplus = new Son_plus;

    //该处由于父类中虚函数原因会调用子类中的同名非虚函数函数
    father->fun();
    //该处由于子类中没有与父类同名的函数，故父类中的虚函数会被启用且调用
    father->fun_plus();
    //该处由于子类的空间不同，故会调用不同子类中的同名非虚函数函数
    father_to_Sonplus->fun();
    system("pause");
    return 0;
}