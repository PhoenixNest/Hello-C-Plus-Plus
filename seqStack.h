#ifndef _SEQ_STACK_H_
#define _SEQ_STACK_H_

#include "Stack.H"

template <class T>
class seqStack : public Stack<T>
{
private:
    T *data;       //* 顺序栈中元素的数组
    int top;       //* 顺序栈顶指针，指向栈顶元素
    int maxSize;   //* 顺序栈的大小
    void resize(); //* 扩顺序栈空间

public:
    //* 构造函数
    seqStack(int initSize = 100)
    {
        if (initSize <= 0)
            throw errorSize();

        data = new T[initSize]; //* 数组
        maxSize = initSize;     //* 当top == maxSize - 1，则表示栈满
        top = -1;               //* 初始时top = -1，表示栈空
    }

    ~seqStack() { delete[] data; };          //* 析构函数
    bool empty() const { return top == -1; } //* 判栈空
    int size() const { return top + 1; }     //* 返回顺序栈大小
    void clear()                             //* 清空顺序栈
    {
        //* 直接将top指针初始化即可清空栈
        top = -1;
    };
    void push(const T &value); //* 顺序栈进栈
    T pop();                   //* 顺序栈出栈
    T getTop() const;          //* 获取顺序栈栈顶元素
};

//* 进栈
//** 时间复杂度：栈满时：O(n)，栈未满时：O(1)
template <class T>
void seqStack<T>::push(const T &value)
{
    //* 当top == maxSize - 1，表示栈满
    if (top == maxSize - 1)
        resize(); //* 若栈满仍插入，则会导致上溢

    // ++top;
    // data[top] = value;
    //* --- 等效于下方代码 ---
    data[++top] = value; //* 修改栈顶指针，元素进栈，先+1后写入
}

//* 出栈
//** 时间复杂度：O(1)
template <class T>
T seqStack<T>::pop()
{
    if (empty()) //* 空栈无法出栈，即下溢
        throw outOfRange();

    // --top;
    // return data[top]
    //* --- 等效于下方代码 ---
    return data[top--]; //* 修改栈顶指针，元素出栈，先-1后出返回
}

//* 取栈顶元素
//** 时间复杂度：O(1)
template <class T>
T seqStack<T>::getTop() const
{
    if (empty())
        throw outOfRange();

    return data[top]; //* 直接返回栈顶元素
}

//* 扩大栈空间
//** 时间复杂度：O(n)
template <class T>
void seqStack<T>::resize()
{
    T *temp = data;                  //* 将旧栈区数据临时存储
    data = new T[2 * maxSize];        //* 扩大栈区大小
    for (int i = 0; i < maxSize; ++i) //* 将旧栈区的数据赋值到新栈区
        data[i] = temp[i];

    maxSize *= 2;
    delete[] temp; //* 释放旧栈区
}

#endif