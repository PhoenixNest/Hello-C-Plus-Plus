#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include <iostream>
#include <stack>
using namespace std;

#include "List.h"

template <class T>
class linkList : public List<T>
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T value, Node *p = NULL)
        {
            data = value;
            next = p;
        }
        Node(Node *p = NULL)
        {
            next = p;
        }
    };

    Node *head;
    Node *tail;
    int length;
    Node *getPosition(int position) const;

    void traverseRecursive(Node *p);
    void traverseNonRecursive1();
    void traverseNonRecursive2();
    void traverseNonRecursive3();

public:
    linkList();
    ~linkList();

    void clear();
    bool empty() const { return head->next == NULL; }
    int size() const { return length; }
    void insert(int position, const T &value);
    void remove(int position);
    int search(const T &value) const;
    T visit(int position) const;

    void traverse() const;
    void inverse();
    void headCreate();
    void tailCreate();
    int prior(const T &value) const;
    linkList *Union(linkList<T> *list);

    void outPut();
};

template <class T>
linkList<T>::linkList()
{
    head = tail = new Node();
    length = 0;
}

template <class T>
linkList<T>::~linkList()
{
    clear();
    delete head;
}

template <class T>
void linkList<T>::clear()
{
    Node *p, *temp;
    p = head->next;
    while (p != NULL)
    {
        temp = p;
        p = p->next;
        delete temp;
    }

    head->next = NULL;
    tail = head;
    length = 0;
}

template <class T>
typename linkList<T>::Node *linkList<T>::getPosition(int position) const
{
    Node *p = head;
    int count = 0;

    if (position < -1 || position > length - 1)
        return NULL;

    while (count <= position)
    {
        p = p->next;
        count++;
    }

    return p;
}

template <class T>
void linkList<T>::insert(int position, const T &value)
{
    Node *p, *q;
    if (position < 0 || position > length)
        throw isOutOfRange();
    p = getPosition(position - 1);
    q = new Node(value, p->next);
    p->next = q;
    if (p == tail)
        tail = q;

    length++;
}

template <class T>
void linkList<T>::remove(int position)
{
    Node *pre, *p;
    if (position < 0 || position > length - 1)
        throw isOutOfRange();

    pre = getPosition(position - 1);
    p = pre->next;
    if (p == tail)
    {
        tail = pre;
        pre->next = NULL;
        delete p;
    }
    else
    {
        pre->next = p->next;
        delete p;
    }

    length--;
}

template <class T>
void linkList<T>::traverse() const
{
    Node *p = head->next;
    cout << "traverse: ";
    while (p != NULL)
    {
        cout << p->data << "---";
        p = p->next;
    }

    cout << endl;
}

template <class T>
int linkList<T>::search(const T &value) const
{
    Node *p = head->next;
    int count = 0;
    while (p != NULL && p->data != value)
    {
        p = p->next;
        count++;
    }

    if (p == NULL)
        return -1;
    else
        return count;
}

template <class T>
T linkList<T>::visit(int position) const
{
    Node *p = head->next;
    int count = 0;

    if (position < 0 || position > length - 1)
        throw isOutOfRange();

    while (count < position)
    {
        p = p->next;
        count++;
    }

    return p->data;
}

template <class T>
void linkList<T>::headCreate()
{
    Node *p;
    T value, flag;
    cout << "input Elements, ended with: ";
    cin >> flag;

    while (cin >> value, value != flag)
    {
        p = new Node(value, head->next);
        head->next = p;
        if (head == tail)
            tail = p;

        length++;
    }
}

template <class T>
void linkList<T>::tailCreate()
{
    Node *p;
    T value, flag;
    cout << "input Elements, ended with: ";
    cin >> flag;

    while (cin >> value, value != flag)
    {
        p = new Node(value, NULL);
        tail->next = p;
        tail = p;
        length++;
    }
}

template <class T>
void linkList<T>::inverse()
{
    Node *p, *temp;
    p = head->next;
    head->next = NULL;
    if (p)
        tail = p;

    while (p)
    {
        temp = p->next;
        p->next = head->next;
        head->next = p;
        p = temp;
    }
}

template <class T>
int linkList<T>::prior(const T &value) const
{
    Node *p = head->next;
    Node *pre = NULL;
    int count = -1;
    while (p && p->data != value)
    {
        pre = p;
        p = p->next;
        count++;
    }

    if (p == NULL)
        return -1;
    else
        return count;
}

template <class T>
linkList<T> *linkList<T>::Union(linkList<T> *listB)
{
    Node *pa, *pb, *pc;
    linkList<T> *listC = this;
    pa = head->next;
    head->next = NULL;
    pb = (listB->head)->next;
    (listB->head)->next = NULL;
    pc = listC->head;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }

    if (pa)
    {
        pc->next = pa;
        listC->tail = tail;
    }
    else
    {
        pc->next = pb;
        listC->tail = listB->tail;
    }

    listC->length = length + listB->length;

    delete listB;
    return listC;
}

template <class T>
void linkList<T>::outPut()
{
    cout << "递归: " << endl;
    traverseRecursive(head->next);
    cout << endl;
    cout << "非递归1: ";
    traverseNonRecursive1();
    cout << endl;
    cout << "非递归2: ";
    traverseNonRecursive2();
    cout << endl;
    cout << "非递归3: ";
    traverseNonRecursive3();
    cout << endl;
}

template <class T>
void linkList<T>::traverseRecursive(Node *p)
{
    if (p)
    {
        cout << p->data << "---";
        traverseRecursive(p->next);
    }
}

template <class T>
void linkList<T>::traverseNonRecursive1()
{
    Node *p = head->next;
Lb1:
    if (p)
    {
        cout << p->data << "---";
        p = p->next;
        goto Lb1;
    }
}

template <class T>
void linkList<T>::traverseNonRecursive2()
{
    Node *temp = head->next;
    while (temp != NULL)
    {
        cout << temp->data << "---";
        temp = temp->next;
    }

    cout << endl;
}

template <class T>
void linkList<T>::traverseNonRecursive3()
{
    stack<Node *> s;
    Node *temp = head->next;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->next;
    }
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        cout << temp->data << "---";
    }
    cout << endl;
}

#endif