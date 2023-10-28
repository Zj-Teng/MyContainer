#include <iostream>
#include "my_stack.h"
#include "my_bst.h"
#include "my_heap.h"
#include "vector"
#include "my_avltree.h"

using namespace std;

void run_heap();

void run_bst();

void run_avlt();

int main() {
//    run_heap();
//    run_bst();
    run_avlt();

    return 0;
}

void run_heap() {
    vector<int> vec = {4, 2, 1, 6, 32, 7};
    MyMaxHeap mp(vec);
    cout << mp.getMax() << endl;
}

void run_bst() {
    vector<int> vec = { 35, 1, 56, 34, 2};
    MyBinaryTree mbt;

    for (auto v: vec) {
        mbt.insert(v);
    }

    cout << "size: " << mbt.size() << endl << mbt << endl;
    mbt.remove(35);
    cout << "size: " << mbt.size() << endl << mbt << endl;
}

void run_avlt() {
    vector<int> vec = { 35, 1, 56, 34, 2};
    MyAVLTree mavt;

    for (auto v: vec) {
        mavt.insert(v);
    }

    cout << "size: " << mavt.size() << endl << mavt << endl;
    mavt.remove(35);
    cout << "size: " << mavt.size() << endl << mavt << endl;
}
