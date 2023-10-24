//
// Created by TeTng on 2023/10/24.
//

#ifndef MYCONTAINER_MY_HEAP_H
#define MYCONTAINER_MY_HEAP_H

#include "iostream"
#include "string"
#include "vector"

class MyMaxHeap {
private:
    std::vector<int> data_;

    int parent(int index);

    void siftUp(int index);

    void siftDown(int index);

    void heapify();

    int leftChild(int index);

    int rightChild(int index);

public:
    explicit MyMaxHeap(int capacity);

    explicit MyMaxHeap(std::vector<int>& data);

    ~MyMaxHeap() = default;

    bool isEmpty();

    void add(int element);

    int size();

    int getMax();
};

#endif //MYCONTAINER_MY_HEAP_H
