//
// Created by Teng on 2023/10/3.
//

#ifndef CONTAINER_MY_TREE_H
#define CONTAINER_MY_TREE_H

#include "vector"
#include "iostream"

class TreeNode {
public:
    int value_ = 0;
    TreeNode *left_ = nullptr;
    TreeNode *right_ = nullptr;

    TreeNode() = default;

    explicit TreeNode(int val, TreeNode *ltn, TreeNode *rtn);

    virtual ~TreeNode();
};

class MyBinaryTree {
private:
    TreeNode *root_ = nullptr;
    int size_;

    bool isContain(TreeNode *node, int value);

    TreeNode *remove(TreeNode *node, int value);

    TreeNode *removeMinNode(TreeNode *node);

    TreeNode *removeMaxNode(TreeNode *node);

    void insert(TreeNode *node, int value);

public:
    explicit MyBinaryTree();

    virtual ~MyBinaryTree();

    TreeNode *getRoot() const;

    void insert(int value);

    bool isContain(int value);

    std::vector<TreeNode *> preOrderTraverse();

    std::vector<TreeNode *> inOrderTraverse();

    std::vector<TreeNode *> postOrderTraverse();

    int size() const;

    bool isEmpty();

    void remove(int value);

    TreeNode *getMinNode(TreeNode *nRoot);

    TreeNode *getMaxNode(TreeNode *nRoot);

    friend std::ostream &operator<<(std::ostream &cout, MyBinaryTree &mbt);
};

#endif //CONTAINER_MY_TREE_H
