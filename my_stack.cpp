//
// Created by Teng on 2023/10/2.
//

#include "my_stack.h"
#include "iostream"

using namespace std;

MyStack::MyStack(int capacity) {
    size_ = 0;
    capacity_ = capacity;
    data_ = new int[capacity];
}

MyStack::~MyStack() {
    delete data_;
    data_ = nullptr;
}

void MyStack::push(int val) {
    if (size_ >= capacity_){
        int* new_data = new int[2 * capacity_];
        memcpy(new_data, data_, sizeof(int) * capacity_);
        capacity_ *= 2;
        delete data_;
        data_ = new_data;
    }

    *(data_ + size_) = val;
    size_ ++;
}

void MyStack::pop() {
    size_ --;
}

bool MyStack::empty() const {
    return size_ == 0;
}

int MyStack::size() const {
    return size_;
}
