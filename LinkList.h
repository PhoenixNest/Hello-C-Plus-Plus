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
        T data;     //* 结点数据域
        Node *next; //* 结点指针域
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

    Node *head; //* 单链表头指针
    Node *tail; //* 单链表尾指针
    int length; //* 单链表表长

    Node *getPosition(int position) const; //* 返回指向position元素的指针

    void traverseRecursive(Node *p);
    void traverseNonRecursive1();
    void traverseNonRecursive2();
    void traverseNonRecursive3();

public:
    linkList();  //* 构造函数
    ~linkList(); //* 析构函数

    void clear();                                     //* 清空单链表，使其成为空表
    bool empty() const { return head->next == NULL; } //* 判空
    int size() const { return length; }               //* 返回单链表的当前实际长度
    void insert(int position, const T &value);        //* 在位置position上插入一个新元素，表长+1
    void remove(int position);                        //* 删除位于position的元素
    int search(const T &value) const;                 //* 查找值为value的元素在单链表中第一次出现的位置
    T visit(int position) const;                      //* 访问在position位置上的单链表的值

    void traverse() const;           //* 遍历单链表
    void inverse();                  //* 逆置单链表
    void headCreate();               //* 头插法创建单链表
    void tailCreate();               //* 尾插法创建单链表
    int prior(const T &value) const; //* 查找值为value的元素的前驱结点
    linkList *Union(linkList<T> *list);

    void outPut();
};

//* 构造函数
//** 时间复杂度：O(1)
template <class T>
linkList<T>::linkList()
{
    head = tail = new Node();
    length = 0;
}

//* 析构函数
//** 时间复杂度：O(n)
template <class T>
linkList<T>::~linkList()
{
    clear();
    delete head;
}

//* 清空单链表
//** 时间复杂度：O(n)
template <class T>
void linkList<T>::clear()
{
    Node *p, *temp;   //* p为工作指针，指向首元结点
    p = head->next;   //* 防止意外修改头指针
    while (p != NULL) //* 等效于：while(p){}
    {
        temp = p;
        p = p->next; //* 指针后移
        delete temp;
    }

    head->next = NULL; //* 头结点指针域置空
    tail = head;       //* 头尾指针均指向头结点
    length = 0;
}

//* 求表长
//** 时间复杂度：O(n)
// template <class T>
// int linkList<T>::size() const
// {
//     return length; //* 直接返回length
// }
//*** 若单链表中未设置变量length存储当前表长，则需要遍历整个单链表以计算表长
// template <class T>
// int linkList<T>::size() const
// {
//     Node *p = head->next; //* 从头到尾遍历整个单链表
//     int count = 0;
//     while (p != NULL)
//     {
//         count++;
//         p = p->next;
//     }
//
//     return count;
// }

//* 遍历单链表
//** 时间复杂度：O(n)
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

//* 查找位于position位置的元素
//** 时间复杂度：o(n)
template <class T>
typename linkList<T>::Node *linkList<T>::getPosition(int position) const
{
    Node *p = head; //* 查找指针p初始指向头节点
    int count = 0;

    if (position < -1 || position > length - 1) //* 合法查找位置为(-1..n-1)
        return NULL;                            //* 当要查找的position非法时返回NULL

    while (count <= position)
    {
        p = p->next;
        count++;
    }

    return p; //* 返回位于position位置的结点的指针
}

//* 在单链表的position位置插入值为value的元素，挂链
//** 时间复杂度：O(n)
//* ------------------------------------------------
//*** s为指向新结点的指针，p为指向position-1位置元素的指针
//*** (1) s->next = p->next
//*** (2) p->next = s
//* ------------------------------------------------
//*** 上述也可表示为：
//*** p指向当前结点，pre表示前一个结点的指针，在*p前（*pre后）插入元素q
//*** (1) q->next = pre->next
//*** (2) pre->next = q
template <class T>
void linkList<T>::insert(int position, const T &value)
{
    Node *p, *q;
    if (position < 0 || position > length) //* 合法位置(0..n)
        throw outOfRange();

    p = getPosition(position - 1); //* p为指向position-1位置的指针
    q = new Node(value, p->next);  //* 生成新结点
    p->next = q;                   //* q结点插入到p结点的后面
    if (p == tail)                 //* 若在表尾插入
        tail = q;                  //* 则修改表尾指针即可

    length++;
}

//* 在单链表中删除位于position位置的元素
//** 时间复杂度：O(n)
//*** p指向当前结点(即待删除结点)，pre表示前一个结点的指针
//*** (1) pre->next = p->next || 也可写成：pre->next = pre->next->next，其中将pre->next看成一个结点(即待删除结点)指针
//*** (2) delete p
template <class T>
void linkList<T>::remove(int position)
{
    Node *pre, *p;
    if (position < 0 || position > length - 1)
        throw outOfRange();

    pre = getPosition(position - 1); //* pre为指向position-1位置，即待删除元素的前一个元素的指针
    p = pre->next;                   //* p为指向pre指针的下一个结点的指针，即指向待删除结点
    if (p == tail)                   //* 若删除元素位于表尾
    {
        tail = pre;       //* 则直接修改表尾
        pre->next = NULL; //* 并将待删除元素的前一个元素的指针域指向NULL
        delete p;         //* 释放待删除结点
    }
    else //* 若删除元素位于表间
    {
        pre->next = p->next; //* 将待删除结点的next指针交付给前一个结点的指针域
        delete p;            //* 释放待删除结点
    }

    length--;
}

//* 单链表按值查找
//** 时间复杂度：O(n)
template <class T>
int linkList<T>::search(const T &value) const
{
    Node *p = head->next; //* 从头结点开始扫描链表
    int count = 0;

    //* 当p不为空与p所指向的data域的值不等于value时，继续扫描链表
    //* 结束循环条件：指针p为NULL
    while (p != NULL && p->data != value)
    {
        p = p->next;
        count++;
    }

    if (p == NULL) //* 当p为空时(空表)，直接返回非法值
        return -1;
    else
        return count; //* 返回value在链表中的位置
}

//* 取单链表在position位置的值
template <class T>
T linkList<T>::visit(int position) const
{
    Node *p = head->next; //* 顺链查，从头开始扫描链表
    int count = 0;

    if (position < 0 || position > length - 1)
        throw outOfRange();

    while (count < position) //* 向后扫描，直到p指向第个元素或p为空
    {
        p = p->next;
        count++;
    }

    return p->data; //* 取出position位置的元素的值
}

//* 头插法创建单链表，可用于逆置链表
//* Example：根据线性表(5,4,3,2,1)创建单链表，则读入数据的顺序应为：1,2,3,4,5，和线性表中的逻辑顺序正好相反
//** 元素插入在链表头部，从后往前插入元素
//** 时间复杂度：O(n)
template <class T>
void linkList<T>::headCreate()
{
    Node *p;
    T value, flag;
    cout << "input Elements, ended with: ";
    cin >> flag; //* 输入结束标志

    while (cin >> value, value != flag)
    {
        p = new Node(value, head->next);
        head->next = p;   //* 结点p插入到头结点后面
        if (head == tail) //* 原链表为空，则结点p为尾结点
            tail = p;

        length++;
    }
}

//* 尾插法创建单链表
//* Example：根据线性表(1,2,3,4,5)创建单链表，则读入顺序应为：1,2,3,4,5，读入顺序与单链表的结点顺序相同
//** 时间复杂度：O(n)
template <class T>
void linkList<T>::tailCreate()
{
    Node *p;
    T value, flag;
    cout << "input Elements, ended with: ";
    cin >> flag; //* 输入结束标志

    while (cin >> value, value != flag)
    {
        p = new Node(value, NULL);
        tail->next = p; //* 给尾指针的指针域赋值新的元素，结点p插入到尾结点的后面
        tail = p;       //* 结点p成为新的尾结点
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