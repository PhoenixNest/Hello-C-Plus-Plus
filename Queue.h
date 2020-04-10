#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
    virtual bool empty() const = 0;           //* 判队空
    virtual int size() const = 0;             //* 求队长
    virtual void clear() = 0;                 //* 清空队列
    virtual void enQueue(const T &value) = 0; //* 入队
    virtual T deQueue() = 0;                  //* 出队
    virtual T getHead() const = 0;            //* 获取队头元素
    virtual ~Queue();                         //* 析构函数
};

class outOfRange : public exception
{
public:
    const char *what() const throw()
    {
        return "ERROR, out of range";
    }
};

class errorSize : public exception
{
public:
    const char *what() const throw()
    {
        return "ERROR, error size";
    }
};

#endif