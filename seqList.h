#ifndef _SEQ_LIST_H_
#define _SEQ_LIST_H_
#include <iostream>
using namespace std;

#include "List.H"

template <class T>
class seqList : public List<T>
{
private:
    T *data;       //* 动态数组
    int length;    //* 当前顺序表表长
    int maxSize;   //* 顺序表最大长度
    void resize(); //* 表满时扩大表空间

public:
    seqList(int initSize = 10);   //* 构造函数
    seqList(seqList &list);       //* 拷贝构造
    ~seqList() { delete[] data; } //* 析构函数

    void clear() { length = 0; }               //* 置空
    bool empty() const { return length == 0; } //* 判空
    int size() const { return length; }        //* 返回表长
    void traverse() const;                     //* 遍历当前表
    void inverse();                            //* 逆置当前表

    void insert(int position, const T &value); //* 在position位置插入值为value的元素
    void remove(int position);                 //* 删除位于position的元素，length - 1
    int search(const T &value) const;          //* 查找值为value的元素在表中的值
    T visit(int position) const;               //* 访问position位置元素的值

    bool Union(seqList<T> &list);
};

//* 构造函数
template <class T>
seqList<T>::seqList(int initSize)
{
    if (initSize <= 0)
        throw errorSize();

    maxSize = initSize;
    data = new T[maxSize];
    length = 0;
}

//* 拷贝构造函数(动态分配)
template <class T>
seqList<T>::seqList(seqList &seqList)
{
    maxSize = seqList.maxSize;
    length = seqList.length;
    data = new T[maxSize];
    for (int i = 0; i < length; ++i)
        data[i] = seqList.data[i];
}

//* 在position位置插入值为value的元素
//** 时间复杂度：O(n)
//** 空间复杂度：O(1)
//*** 平均移动元素次数(期望值)：n/2
template <class T>
void seqList<T>::insert(int position, const T &value)
{
    if (position < 0 || position > length)
        //* 判断是否越界
        throw outOfRange();

    if (length == maxSize)
        //* 当表满时，扩大表容量
        resize();

    for (int j = length; j > position; j--)
        //* 后移在插入位置position之后的所有元素
        data[j] = data[j - 1];

    //* 在空出位置插入值为value的元素
    data[position] = value;

    //* 表长 +1
    ++length;
}

//* 删除位于position位置的元素
//* 元素个数不变，表长 -1
//** 时间复杂度：O(n)
template <class T>
void seqList<T>::remove(int position)
{
    if (position < 0 || position > length - 1)
        //* 判断是否越界
        throw outOfRange();

    for (int j = position; j < length - 1; j++)
        //* 前移在删除位置position之后的所有元素
        data[j] = data[j + 1];

    //* 表长 -1
    --length;
};

//* 查找值为value的元素
//** 时间复杂度：O(n)
//** 空间复杂度：O(1)
//*** 平均移动元素次数(期望值)：(n + 1) / 2
template <class T>
int seqList<T>::search(const T &value) const
{
    for (int i = 0; i < length; i++)
        if (value == data[i])
            return i;

    return -1;
}

//* 访问位于position位置的元素
template <class T>
T seqList<T>::visit(int position) const
{
    if (position < 0 || position > length - 1)
        throw outOfRange();
    return data[position];
}

//* 表满时扩大表空间
template <class T>
void seqList<T>::resize()
{
    T *p = data;           //* 指针p指向原顺序表空间
    maxSize *= 2;          //* 扩大2倍表空间
    data = new T[maxSize]; //* 将旧的数据指向新的表空间

    for (int i = 0; i < length; ++i) //* 复制元素至扩大后的新表
        data[i] = p[i];

    delete[] p;
}

//* 遍历顺序表
//** 时间复杂度：O(n)
//** 空间复杂度：O(1)
template <class T>
void seqList<T>::traverse() const
{
    if (empty())
    {
        cout << "is Empty" << endl;
    }
    else
    {
        cout << "current Element" << endl;
        for (int i = 0; i < maxSize; i++)
        {
            cout << data[i] << "---";
        }

        cout << endl;
    }
}

//* 逆置当前线性表
//** 时间复杂度：O(n)
//** 空间复杂度：O(1)
//*** 总交换次数：|length/2|向下取整
template <class T>
void seqList<T>::inverse()
{
    T temp;
    //* 控制交换次数
    for (int i = 0; i < length / 2; i++)
    {
        temp = data[i];
        data[i] = data[length - i - 1];
        data[length - i - 1] = temp;
    }
}

#endif