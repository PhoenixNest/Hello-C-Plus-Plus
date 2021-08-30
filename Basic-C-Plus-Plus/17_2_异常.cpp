#include <iostream>
//异常的头文件
#include <cstdlib>
using namespace std;
int main()
{
    // int i;
    // cin >> i;
    // if (i != 0)
    // {
    //     cout << i;
    // }
    // else if (i == 0)
    // {
    //     abort();
    // }

    try
    {
        int i;
        cin >> i;
        while (i < 10)
        {
            if (i == 5)
            {
                //throw i;
                throw 'E';
            }
            i++;
        }
    }
    //try块中的抛出值i会在catch块的参数列表中进行接收，该catch块可被因参数类型的不同重载
    // catch (int e)
    // {
    //     cout << e << endl;
    // }
    catch (char e)
    {
        cout << e << endl;
    }
    system("pause");
    return 0;
}