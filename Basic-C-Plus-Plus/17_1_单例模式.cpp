#include <iostream>
using namespace std;

class Father
{
    /**
     * 单例模式:
     * 1.将构造函数的类型更改为private(不能实例化对象)或protected(不能实例化对象)
     * 2.通过静态成员申请空间，并返回地址
     * 3.定义一个静态标记，记录对象的个数并控制
     * 4.通过析构函数将标记清空或重定义，以重复申请空间
     */
    //private:
  protected:
    Father()
    {
        cout << "Father" << endl;
    }

  public:
    static int flag;

    static Father *fun_father()
    {
        if (flag == 1)
        {
            flag = 0;
            return (new Father);
        }
        else
        {
            return NULL;
        }
    }
    ~Father()
    {
        flag = 1;
    }
};

int Father::flag = 1;

class Son : public Father
{
};

int main()
{
    Father *father = Father::fun_father();
    delete father;

    Father *f = Father::fun_father();
    delete f;

    Son son;

    system("pause");
    return 0;
}