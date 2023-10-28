//
// Created by Teng on 2023/10/3.
//

#include "my_bst.h"
#include "vector"
#include "iostream"

using namespace std;

void preOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    order.push_back(node);
    ::preOrderTraverse(order, node->left_);
    ::preOrderTraverse(order, node->right_);
}

void inOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    ::inOrderTraverse(order, node->left_);
    order.push_back(node);
    ::inOrderTraverse(order, node->right_);
}

void postOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    ::postOrderTraverse(order, node->left_);
    ::postOrderTraverse(order, node->right_);
    order.push_back(node);
}

TreeNode::TreeNode(int val, TreeNode *ltn, TreeNode *rtn) {
    value_ = val;
    left_ = ltn;
    right_ = rtn;
}

TreeNode::~TreeNode() {
    left_ = nullptr;
    right_ = nullptr;
}

MyBinaryTree::~MyBinaryTree() {
    vector<TreeNode *> gc;
    ::inOrderTraverse(gc, root_);
    for (auto tn: gc) {
        delete tn;
    }
    root_ = nullptr;
}

TreeNode *MyBinaryTree::getRoot() const {
    return root_;
}

void MyBinaryTree::insert(TreeNode *node, int value) {
    if (node == nullptr) return;

    int r_val = node->value_;
    if (r_val == value) {
        cerr << "Val in tree" << endl;
        return;
    }

    auto new_node = new TreeNode(value, nullptr, nullptr);
    if (r_val > value && node->left_ == nullptr) {
        node->left_ = new_node;
        size_++;
        return;
    }
    if (r_val < value && node->right_ == nullptr) {
        node->right_ = new_node;
        size_++;
        return;
    }

    if (r_val > value) insert(node->left_, value);
    if (r_val < value) insert(node->right_, value);
}

void MyBinaryTree::insert(int value) {
    if (isEmpty()) {
        auto node = new TreeNode(value, nullptr, nullptr);
        root_ = node;
        size_++;

        return;
    }

    insert(root_, value);
}

bool MyBinaryTree::isContain(TreeNode *node, int value) {
    if (node == nullptr) return false;

    if (node->value_ == value) return true;
    if (value < node->value_) return isContain(node->left_, value);
    if (value > node->value_) return isContain(node->right_, value);

}

bool MyBinaryTree::isContain(int value) {
    if (isEmpty()) {
        cerr << "Tree is empty!" << endl;
        return false;
    }

    return isContain(root_, value);
}

vector<TreeNode *> MyBinaryTree::preOrderTraverse() {
    vector<TreeNode *> preOrder;
    ::preOrderTraverse(preOrder, root_);

    return preOrder;
}

vector<TreeNode *> MyBinaryTree::inOrderTraverse() {
    vector<TreeNode *> inOrder;
    ::inOrderTraverse(inOrder, root_);

    return inOrder;
}

vector<TreeNode *> MyBinaryTree::postOrderTraverse() {
    vector<TreeNode *> postOrder;
    ::postOrderTraverse(postOrder, root_);

    return postOrder;
}

MyBinaryTree::MyBinaryTree() {
    size_ = 0;
    root_ = nullptr;
}

int MyBinaryTree::size() const {
    return size_;
}

bool MyBinaryTree::isEmpty() {
    return size_ == 0;
}

TreeNode *MyBinaryTree::getMinNode(TreeNode *nRoot) {
    if (isEmpty()) {
        cerr << "The tree is empty" << endl;
        return nullptr;
    }

    if (nRoot->left_ == nullptr) return nRoot;
    return getMinNode(nRoot->left_);
}

TreeNode *MyBinaryTree::getMaxNode(TreeNode *nRoot) {
    if (isEmpty()) {
        cerr << "The tree is empty" << endl;
        return nullptr;
    }

    if (nRoot->right_ == nullptr) return nRoot;
    return getMinNode(nRoot->right_);
}

TreeNode *MyBinaryTree::removeMinNode(TreeNode *node) {
    if (node->left_ == nullptr) {
        TreeNode *rn = node->right_;
        node->right_ = nullptr;
        size_--;

        return rn;
    }

    node->left_ = removeMinNode(node->left_);
    return node;
}

TreeNode *MyBinaryTree::removeMaxNode(TreeNode *node) {
    if (node->right_ == nullptr) {
        TreeNode *ln = node->left_;
        node->left_ = nullptr;
        size_--;

        return ln;
    }

    node->right_ = removeMinNode(node->right_);
    return node;
}

TreeNode *MyBinaryTree::remove(TreeNode *node, int value) {
    if (node == nullptr) return nullptr;

    if (node->value_ == value) {
        if (node->left_ == nullptr) {
            TreeNode *rn = node->right_;
            node->right_ = nullptr;
            return rn;
        }
        if (node->right_ == nullptr) {
            TreeNode *ln = node->left_;
            node->left_ = nullptr;
            return ln;
        }

        TreeNode *successor = MyBinaryTree::getMinNode(node->right_);
        successor->right_ = removeMinNode(node->right_);
        successor->left_ = node->left_;

        node->left_ = nullptr;
        node->right_ = nullptr;
//        delete node;

        return successor;
    } else if (node->value_ > value) {
        node->left_ = remove(node->left_, value);
        return node;
    } else if (node->value_ < value) {
        node->right_ = remove(node->right_, value);
        return node;
    }
}

void MyBinaryTree::remove(int value) {
    if (root_ == nullptr) return;

    root_ = remove(root_, value);
}

std::ostream &operator<<(ostream &cout, MyBinaryTree &mbt) {
    if (mbt.isEmpty()) {
        cout << "The tree is empty()";
        return cout;
    }

    vector<TreeNode *> tr = mbt.inOrderTraverse();
    for (auto n: tr) {
        cout << n->value_ << " ";
    }

    return cout;
}
