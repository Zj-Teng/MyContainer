#include <iostream>
#include "my_stack.h"
#include "my_tree.h"

using namespace std;

int main() {
    MyBinaryTree mbt;
    mbt.insert(1);
    mbt.insert(2);
    mbt.insert(0);
    mbt.insert(-1);
    vector<TreeNode*> nodes = mbt.inOrderTraverse();
    cout << nodes.size() << endl;
    for (auto n: nodes){
        cout << n->getValue() << " ";
    }
    cout << endl;

    return 0;
}
