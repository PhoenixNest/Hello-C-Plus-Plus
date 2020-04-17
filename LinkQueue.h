#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_
#include <iostream>

#include "Queue.H"

template <class T>
class linkQueue : public Queue<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value, Node *n = NULL)
        {
            data = value;
            next = n;
        }

        Node() : next(NULL) {}
        ~Node();
    };

    Node *front, *rear;

public:
    linkQueue() { front = rear = NULL; }
    ~linkQueue();
    void clear();
    bool empty() const { return front == NULL; };
    int size() const;
    void enQueue(const T &value);
    T deQueue();
    T getHead() const;
};

template <class T>
linkQueue<T>::~linkQueue<T>()
{
    Node *p;
    while (front != NULL)
    {
        p = front;
        front = front->next;
        delete p;
    }
}

template <class T>
void linkQueue<T>::clear()
{
    Node *p;
    while (front != NULL)
    {
        p = front;
        front = front->next;
        delete p;
    }

    rear = NULL;
}

template <class T>
int linkQueue<T>::size() const
{
    Node *p = front;
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }

    return count;
}

template <class T>
void linkQueue<T>::enQueue(const T &value)
{
    if (rear == NULL)
    {
        front = rear = new Node(value);
    }
    else
    {
        rear->next = new Node(value);
        rear = rear->next;
    }
}

template <class T>
T linkQueue<T>::deQueue()
{
    if (empty())
        throw outOfRange();

    Node *p = front;
    T value = front->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;

    delete p;
    return value;
}

template <class T>
T linkQueue<T>::getHead() const
{
    if (empty())
        throw outOfRange();

    return front->data;
}

#endif