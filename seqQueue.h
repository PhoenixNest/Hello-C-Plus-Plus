#ifndef _SEQ_QUEUE_H_
#define _SEQ_QUEUE_H_

#include "Queue.h"

template <class T>
class seqQueue : public Queue<T>
{
private:
    T *data;       //* 存放数据的数组
    int maxSize;   //* 队列大小
    int front;     //* 队首指针
    int rear;      //* 队尾指针
    void resize(); //* 扩大队列容量

public:
    seqQueue(int size = 100);
    ~seqQueue() { delete[] data; }
    void clear() { front = rear = 1; }
    bool empty() const { return front == rear; }
    bool full() const { (rear + 1) % maxSize == front; }
    int size() const { return (rear - front + maxSize) % maxSize; }
    void enQueue(const T &value);
    T deQueue();
    T getHead() const;
};

//* 初始化
template <class T>
seqQueue<T>::seqQueue(int initSize)
{
    if (initSize <= 0)
        throw errorSize();

    data = new T[initSize];
    maxSize = initSize;
    front = rear = -1;
}

//* 进队
template <class T>
void seqQueue<T>::enQueue(const T &value)
{
    if ((rear + 1) % maxSize == front)
        resize();

    rear = (rear + 1) % maxSize;
    data[rear] = value;
}

//* 出队
template <class T>
T seqQueue<T>::deQueue()
{
    if (empty())
        throw outOfRange();

    front = (front + 1) % maxSize;
    return data[front];
}

//* 获取队头元素
template <class T>
T seqQueue<T>::getHead() const
{
    if (empty())
        throw outOfRange();

    return data[(front + 1) % maxSize];
}

//* 扩大队列容量
template <class T>
void seqQueue<T>::resize()
{
    T *p = data;
    data = new T[2 * maxSize];
    for (int i = 1; i < maxSize; ++i)
        data[i] = p[(front + i) % maxSize];

    front = 0;
    rear = maxSize - 1;
    maxSize *= 2;
    delete p;
}

#endif