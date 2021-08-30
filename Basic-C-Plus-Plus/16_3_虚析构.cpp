#include <iostream>
using namespace std;

class Father
{
  public:
    virtual ~Father()
    {
        cout << "Father has been shut down" << endl;
    }
};

class Son : public Father
{
  public:
    ~Son()
    {
        cout << "Son has been shut down" << endl;
    }
};

class Test
{
  public:
    ~Test()
    {
        cout << "Test has been shut down" << endl;
    }
};

int main()
{
    /**
     * 删除父类指针，释放了父类的空间，此时会调用父类的析构函数，但不会调用子类的虚构函数
     * 若想调用子类的析构函数，则将父类的析构函数转为虚析构函数即可
     * 此时会先调用子类的析构函数，再调用父类的虚析构函数
     */
    Father *father = new Son();
    //delete father;

    //谁的类型的指针，就调用谁的析构函数(包括强转)，不在乎原有是谁的指针，只在乎转换为谁的指针
    delete (Test *)father;

    system("pause");
    return 0;
}