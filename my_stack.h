//
// Created by Teng on 2023/10/2.
//

#ifndef CONTAINER_MY_STACK_H
#define CONTAINER_MY_STACK_H

#include "array"

class MyStack{
private:
    int size_ = 0;
    int capacity_ = 0;
    int* data_ = nullptr;

public:
    MyStack(int capacity);

    ~MyStack();

    void push(int val);

    void pop();

    bool empty() const;

    int size() const;
};

#endif //CONTAINER_MY_STACK_H
