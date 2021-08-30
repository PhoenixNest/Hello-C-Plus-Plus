#include <iostream>
using namespace std;

class GrandFather
{
  public:
    GrandFather()
    {
        cout << "GrandFather" << endl;
    }

    ~GrandFather()
    {
        cout << "~GrandFather" << endl;
    }
};

class Father : public GrandFather
{
  public:
    Father()
    {
        cout << "Father" << endl;
    }

    ~Father()
    {
        cout << "~Father" << endl;
    }
};

class Son : public Father
{
  public:
    Son()
    {
        cout << "Son" << endl;
    }

    ~Son()
    {
        cout << "~Son" << endl;
    }
};

int main()
{

    /**
     * 构造函数的继承由高辈分向低辈分调用
     * 
     * 析构函数反之，从低辈分向高辈分调用
     */
    Son *s = new Son;
    cout << "-----" << endl;
    delete s;

    system("pause");
    return 0;
}