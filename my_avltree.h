//
// Created by TeTng on 2023/10/26.
//

#ifndef MYCONTAINER_MY_AVLTREE_H
#define MYCONTAINER_MY_AVLTREE_H

#include "vector"
#include "iostream"

class AVLTreeNode {
public:
    int value_ = 0;
    int height_ = 0;
    AVLTreeNode *left_ = nullptr;
    AVLTreeNode *right_ = nullptr;

    AVLTreeNode() = default;

    explicit AVLTreeNode(int val, AVLTreeNode *ltn, AVLTreeNode *rtn);

    virtual ~AVLTreeNode();
};

class MyAVLTree {
private:
protected:
    AVLTreeNode *root_ = nullptr;
    int size_;

    bool isContain(AVLTreeNode *node, int value);

    AVLTreeNode *remove(AVLTreeNode *node, int value);

    AVLTreeNode *removeMinNode(AVLTreeNode *node);

    AVLTreeNode *removeMaxNode(AVLTreeNode *node);

    int getHeight(AVLTreeNode *node);

    int getBalanceFactor(AVLTreeNode *node);

    AVLTreeNode *insert(AVLTreeNode *node, int value);

    bool isBalanced(AVLTreeNode *node);

    AVLTreeNode *rightRotate(AVLTreeNode *node);

    AVLTreeNode *leftRotate(AVLTreeNode *node);

public:
    explicit MyAVLTree();

    virtual ~MyAVLTree();

    AVLTreeNode *getRoot() const;

    void insert(int value);

    bool isContain(int value);

    std::vector<AVLTreeNode *> preOrderTraverse();

    std::vector<AVLTreeNode *> inOrderTraverse();

    std::vector<AVLTreeNode *> postOrderTraverse();

    int size() const;

    bool isEmpty();

    void remove(int value);

    AVLTreeNode *getMinNode(AVLTreeNode *nRoot);

    AVLTreeNode *getMaxNode(AVLTreeNode *nRoot);

    friend std::ostream &operator<<(std::ostream &cout, MyAVLTree &mbt);

    bool isBST();

    bool isBalanced();
};

#endif //MYCONTAINER_MY_AVLTREE_H
