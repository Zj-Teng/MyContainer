//
// Created by Teng on 2023/10/2.
//

#ifndef CONTAINER_MY_LIST_H
#define CONTAINER_MY_LIST_H

#include "iostream"

class ListNode {
private:
    int val_ = 0;
    ListNode *prev_ = nullptr;
    ListNode *next_ = nullptr;

public:
    ListNode(int val, ListNode *prev, ListNode *next);

    ~ListNode();

    void setValue(int x);

    int getValue() const;

    ListNode *getNext();

    ListNode *getPrev();

    void setNext(ListNode *node);

    void setPrev(ListNode *node);
};

class MyList {
private:
    int size_ = 0;
    ListNode *head_ = nullptr;
    ListNode *back_ = nullptr;

public:
    MyList() = default;

    ~MyList();

    int getSize() const;

    ListNode *getHead();

    ListNode *getBack();

    void setHead(ListNode *ln);

    void setBack(ListNode *ln);

    void push_back(int val);

    void pop_back();

    bool empty() const;

    int at(int index);

    void reverse();

    void push_front(int val);

    void pop_front();
};

#endif //CONTAINER_MY_LIST_H
