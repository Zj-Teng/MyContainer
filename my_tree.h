//
// Created by Teng on 2023/10/3.
//

#ifndef CONTAINER_MY_TREE_H
#define CONTAINER_MY_TREE_H

#include "vector"

class TreeNode {
private:
    int val_ = 0;
    TreeNode *left_ = nullptr;
    TreeNode *right_ = nullptr;

public:
    TreeNode(int val, TreeNode *ltn, TreeNode *rtn);

    ~TreeNode();

    void setValue(int val);

    void setLeft(TreeNode *tn);

    void setRight(TreeNode *tn);

    int getValue() const;

    TreeNode *getLeft();

    TreeNode *getRight();
};

class MyBinaryTree {
private:
    TreeNode *root_ = nullptr;

public:
    MyBinaryTree() = default;

    ~MyBinaryTree();

    TreeNode *getRoot();

    void insert(int val);

    TreeNode *getNode(int val);

    std::vector<TreeNode *> preOrderTraverse();

    std::vector<TreeNode *> inOrderTraverse();

    std::vector<TreeNode *> postOrderTraverse();
};

#endif //CONTAINER_MY_TREE_H
