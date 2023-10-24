//
// Created by Teng on 2023/10/3.
//

#include "my_tree.h"

#include "vector"
#include "iostream"

using namespace std;

void preOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    order.push_back(node);
    preOrderTraverse(order, node->getLeft());
    preOrderTraverse(order, node->getRight());
}

void inOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    preOrderTraverse(order, node->getLeft());
    order.push_back(node);
    preOrderTraverse(order, node->getRight());
}

void postOrderTraverse(vector<TreeNode *> &order, TreeNode *node) {
    if (node == nullptr)
        return;

    preOrderTraverse(order, node->getLeft());
    preOrderTraverse(order, node->getRight());
    order.push_back(node);
}

void insert(TreeNode *root, int val) {
    int r_val = root->getValue();
    if (r_val == val) {
        cerr << "Val in tree" << endl;
        return ;
    }

    auto node = new TreeNode(val, nullptr, nullptr);
    if (r_val > val && root->getLeft() == nullptr){
        root->setLeft(node);
        return ;
    }
    if (r_val < val && root->getRight() == nullptr){
        root->setRight(node);
        return ;
    }

    if (r_val > val) insert(root->getLeft(), val);
    if (r_val < val) insert(root->getRight(), val);
}

TreeNode::TreeNode(int val, TreeNode *ltn, TreeNode *rtn) {
    val_ = val;
    left_ = ltn;
    right_ = rtn;
}

TreeNode::~TreeNode() {
    left_ = nullptr;
    right_ = nullptr;
}

void TreeNode::setValue(int val) {
    val_ = val;
}

void TreeNode::setLeft(TreeNode *tn) {
    left_ = tn;
}

void TreeNode::setRight(TreeNode *tn) {
    right_ = tn;
}

int TreeNode::getValue() const {
    return val_;
}

TreeNode *TreeNode::getLeft() {
    return left_;
}

TreeNode *TreeNode::getRight() {
    return right_;
}

MyBinaryTree::~MyBinaryTree() {
    vector<TreeNode *> gc;
    ::inOrderTraverse(gc, root_);
    for (auto tn: gc) {
        delete tn;
    }
    root_ = nullptr;
}

TreeNode *MyBinaryTree::getRoot() {
    return root_;
}

void MyBinaryTree::insert(int val) {
    if (root_ == nullptr) {
        auto node = new TreeNode(val, nullptr, nullptr);
        root_ = node;

        return;
    }

    ::insert(root_, val);
}

TreeNode *MyBinaryTree::getNode(int val) {
    return nullptr;
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
