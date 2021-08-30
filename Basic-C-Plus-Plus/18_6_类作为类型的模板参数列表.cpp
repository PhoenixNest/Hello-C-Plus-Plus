#include <iostream>
using namespace std;

template <typename X, typename Y>
class Father
{
  public:
    virtual void fun()
    {
        cout << "Father" << endl;
    }
};

int main()
{
    

    system("pause");
    return 0;
}