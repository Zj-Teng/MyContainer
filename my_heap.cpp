//
// Created by TeTng on 2023/10/24.
//

#include "my_heap.h"

using namespace std;

int MyMaxHeap::parent(int index) {
    // 返回index节点的父节点
    if (index == 0) {
        cerr << "index:0 is the root" << endl;
        return 0;
    }

    return (index - 1) / 2;
}

void MyMaxHeap::siftUp(int index) {
    int prt_indx = parent(index);
    while (index > 0 && data_[prt_indx] < data_[index]) {
        int tmp = data_[prt_indx];
        data_[prt_indx] = data_[index];
        data_[index] = tmp;
        index = prt_indx;
        prt_indx = parent(index);
    }
}

void MyMaxHeap::siftDown(int index) {
    while (index < data_.size()) {
        int lc = leftChild(index), rc = rightChild(index);

        if (rc < size() && data_[lc] <= data_[rc]) {
            swap(data_[index], data_[rc]);
            index = rc;
        }else if(lc < size() && data_[lc] >= data_[rc]){
            swap(data_[index], data_[lc]);
            index = lc;
        }
    }
}

void MyMaxHeap::heapify() {
    int curr_idx = parent((size() - 1));
    while (curr_idx >= 0) {
        siftDown(curr_idx --);
    }
}

int MyMaxHeap::leftChild(int index) {
    // 返回左孩子的索引
    return index * 2 + 1;
}

int MyMaxHeap::rightChild(int index) {
    // 返回右孩子的索引
    return index * 2 + 2;
}

MyMaxHeap::MyMaxHeap(int capacity) {
    data_ = vector<int>(capacity, 0);
}

MyMaxHeap::MyMaxHeap(std::vector<int>& data) {
    if (!data_.empty()) {
        data_.clear();
    }
    data_ = data;
    heapify();
}

bool MyMaxHeap::isEmpty() {
    return data_.empty();
}

void MyMaxHeap::add(int element) {
    data_.push_back(element);
    siftUp(size()-1);
}

int MyMaxHeap::size() {
    return (int)data_.size();
}

int MyMaxHeap::getMax() {
    // 获取堆中的最大值（及堆顶）
    if (data_.empty()) {
        cerr << "The heap is empty" << endl;
        return INT_MIN;
    }

    int rst = data_[0];
    swap(data_[0], data_[size() - 1]);
    data_.pop_back();
    siftDown(0);

    return rst;
}
