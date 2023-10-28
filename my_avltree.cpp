//
// Created by TeTng on 2023/10/26.
//

#include "vector"
#include "iostream"
#include "my_avltree.h"

using namespace std;

void preOrderTraverse(vector<AVLTreeNode *> &order, AVLTreeNode *node) {
    if (node == nullptr)
        return;

    order.push_back(node);
    ::preOrderTraverse(order, node->left_);
    ::preOrderTraverse(order, node->right_);
}

void inOrderTraverse(vector<AVLTreeNode *> &order, AVLTreeNode *node) {
    if (node == nullptr)
        return;

    ::inOrderTraverse(order, node->left_);
    order.push_back(node);
    ::inOrderTraverse(order, node->right_);
}

void postOrderTraverse(vector<AVLTreeNode *> &order, AVLTreeNode *node) {
    if (node == nullptr)
        return;

    ::postOrderTraverse(order, node->left_);
    ::postOrderTraverse(order, node->right_);
    order.push_back(node);
}

AVLTreeNode::AVLTreeNode(int val, AVLTreeNode *ltn, AVLTreeNode *rtn) {
    value_ = val;
    left_ = ltn;
    right_ = rtn;
    height_ = 1;
}

AVLTreeNode::~AVLTreeNode() {
    left_ = nullptr;
    right_ = nullptr;
}

MyAVLTree::~MyAVLTree() {
    vector<AVLTreeNode *> gc;
    ::inOrderTraverse(gc, root_);
    for (auto tn: gc) {
        delete tn;
    }
    root_ = nullptr;
}

AVLTreeNode *MyAVLTree::getRoot() const {
    return root_;
}

AVLTreeNode *MyAVLTree::insert(AVLTreeNode *node, int value) {
    if (node == nullptr) {
        size_ ++;
        return new AVLTreeNode(value, nullptr, nullptr);;
    }

    int r_val = node->value_;
    if (r_val == value) {
        cerr << "Val in tree" << endl;
    } else if (r_val > value) {
        node->left_ = insert(node->left_, value);
    }else if (r_val < value) {
        node->right_ = insert(node->right_, value);
    }

    node->height_ = 1 + max(getHeight(node->left_), getHeight(node->right_));
    int balance_factor = getBalanceFactor(node);
    if (balance_factor > 1 && getBalanceFactor(node->left_) >= 0) // LL型
        return rightRotate(node);
    if (balance_factor < -1 && getBalanceFactor(node->right_) <= 0) // RR型
        return leftRotate(node);
    if (balance_factor > 1 && getBalanceFactor(node->left_) < 0) { // LR型
        node->left_ = leftRotate(node->left_);
        return rightRotate(node);
    }
    if (balance_factor < -1 && getBalanceFactor(node->right_) > 0) { // RL型
        node->right_ = rightRotate(node->right_);
        return leftRotate(node);
    }

    return node;
}

void MyAVLTree::insert(int value) {
    root_ = insert(root_, value);
}

bool MyAVLTree::isContain(AVLTreeNode *node, int value) {
    if (node == nullptr) return false;

    if (node->value_ == value) return true;
    if (value < node->value_) return isContain(node->left_, value);
    if (value > node->value_) return isContain(node->right_, value);

}

bool MyAVLTree::isContain(int value) {
    if (isEmpty()) {
        cerr << "Tree is empty!" << endl;
        return false;
    }

    return isContain(root_, value);
}

vector<AVLTreeNode *> MyAVLTree::preOrderTraverse() {
    vector<AVLTreeNode *> preOrder;
    ::preOrderTraverse(preOrder, root_);

    return preOrder;
}

vector<AVLTreeNode *> MyAVLTree::inOrderTraverse() {
    vector<AVLTreeNode *> inOrder;
    ::inOrderTraverse(inOrder, root_);

    return inOrder;
}

vector<AVLTreeNode *> MyAVLTree::postOrderTraverse() {
    vector<AVLTreeNode *> postOrder;
    ::postOrderTraverse(postOrder, root_);

    return postOrder;
}

MyAVLTree::MyAVLTree() {
    size_ = 0;
    root_ = nullptr;
}

int MyAVLTree::size() const {
    return size_;
}

bool MyAVLTree::isEmpty() {
    return size_ == 0;
}

AVLTreeNode *MyAVLTree::getMinNode(AVLTreeNode *nRoot) {
    if (isEmpty()) {
        cerr << "The tree is empty" << endl;
        return nullptr;
    }

    if (nRoot->left_ == nullptr) return nRoot;
    return getMinNode(nRoot->left_);
}

AVLTreeNode *MyAVLTree::getMaxNode(AVLTreeNode *nRoot) {
    if (isEmpty()) {
        cerr << "The tree is empty" << endl;
        return nullptr;
    }

    if (nRoot->right_ == nullptr) return nRoot;
    return getMinNode(nRoot->right_);
}

AVLTreeNode *MyAVLTree::removeMinNode(AVLTreeNode *node) {
    if (node->left_ == nullptr) {
        AVLTreeNode *rn = node->right_;
        node->right_ = nullptr;
        size_--;

        return rn;
    }

    node->left_ = removeMinNode(node->left_);
    return node;
}

AVLTreeNode *MyAVLTree::removeMaxNode(AVLTreeNode *node) {
    if (node->right_ == nullptr) {
        AVLTreeNode *ln = node->left_;
        node->left_ = nullptr;
        size_--;

        return ln;
    }

    node->right_ = removeMinNode(node->right_);
    return node;
}

AVLTreeNode *MyAVLTree::remove(AVLTreeNode *node, int value) {
    if (node == nullptr) return nullptr;

    AVLTreeNode *ret_node = nullptr;
    if (node->value_ == value) {
        if (node->left_ == nullptr) {
            AVLTreeNode *rn = node->right_;
            node->right_ = nullptr;
            ret_node = rn;
        }
        if (node->right_ == nullptr) {
            AVLTreeNode *ln = node->left_;
            node->left_ = nullptr;
            ret_node = ln;
        }

        AVLTreeNode *successor = MyAVLTree::getMinNode(node->right_);
        successor->right_ = removeMinNode(node->right_);
        successor->left_ = node->left_;

        node->left_ = nullptr;
        node->right_ = nullptr;
        ret_node = successor;

    } else if (node->value_ > value) {
        node->left_ = remove(node->left_, value);
        ret_node = node;
        return node;
    } else if (node->value_ < value) {
        node->right_ = remove(node->right_, value);
        ret_node = node;
        return node;
    }

    if (ret_node == nullptr) return nullptr;

    ret_node->height_ = 1 + max(getHeight(ret_node->left_), getHeight(ret_node->right_));
    int balance_factor = getBalanceFactor(ret_node);
    if (balance_factor > 1 && getBalanceFactor(ret_node->left_) >= 0) // LL型
        return rightRotate(ret_node);
    if (balance_factor < -1 && getBalanceFactor(ret_node->right_) <= 0) // RR型
        return leftRotate(ret_node);
    if (balance_factor > 1 && getBalanceFactor(ret_node->left_) < 0) { // LR型
        ret_node->left_ = leftRotate(ret_node->left_);
        return rightRotate(ret_node);
    }
    if (balance_factor < -1 && getBalanceFactor(ret_node->right_) > 0) { // RL型
        ret_node->right_ = rightRotate(ret_node->right_);
        return leftRotate(ret_node);
    }

    return ret_node;
}

void MyAVLTree::remove(int value) {
    if (root_ == nullptr) return;

    root_ = remove(root_, value);
}

std::ostream &operator<<(ostream &cout, MyAVLTree &mbt) {
    if (mbt.isEmpty()) {
        cout << "The tree is empty()";
        return cout;
    }

    vector<AVLTreeNode *> tr = mbt.inOrderTraverse();
    for (auto n: tr) {
        cout << n->value_ << " ";
    }

    return cout;
}

int MyAVLTree::getHeight(AVLTreeNode *node) {
    if (node == nullptr) return 0;

    return node->height_;
}

int MyAVLTree::getBalanceFactor(AVLTreeNode *node) {
    if (node == nullptr) return 0;

    return getHeight(node->left_) - getHeight(node->right_);
}

bool MyAVLTree::isBST() {
    vector<AVLTreeNode *> vec = inOrderTraverse();
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i - 1] > vec[i]) return false;
    }

    return true;
}

bool MyAVLTree::isBalanced(AVLTreeNode *node) {
    if (node == nullptr) return true;

    int balance_factor = getBalanceFactor(node);
    if (abs(balance_factor) > 1) return false;

    return isBalanced(node->left_) && isBalanced(node->right_);
}

bool MyAVLTree::isBalanced() {
    return isBalanced(root_);
}

AVLTreeNode *MyAVLTree::rightRotate(AVLTreeNode *node) {
    /* 以node为根的子树做右旋转，返回旋转后新的根节点
     *         y                           x
     *       /   \                       /   \
     *      x     T4                    z     y
     *     /  \       --------->       /  \  /  \
     *    z    T3                     T1  T2 T3  T4
     *   / \
     *  T1  T2
     * */

    AVLTreeNode *new_root = node->left_, *t_node = new_root->right_;

    new_root->right_ = node;
    node->left_ = t_node;

    // 更新height
    node->height_ = 1 + max(getHeight(node->left_), getHeight(node->right_));
    new_root->height_ = 1 + max(getHeight(new_root->left_), getHeight(new_root->right_));

    return new_root;
}

AVLTreeNode *MyAVLTree::leftRotate(AVLTreeNode *node) {
    /* 以node为根的子树做左旋转，返回旋转后新的根节点
     *       y                             x
     *     /  \                          /   \
     *    T1   x      向左旋转 (y)       y     z
     *        / \   - - - - - - - ->   / \   / \
     *      T2  z                     T1 T2 T3 T4
     *         / \
     *        T3 T4
     * */
    AVLTreeNode *new_root = node->right_, *t_node = new_root->left_;
    new_root->left_ = node;
    node->right_ = t_node;

    node->height_ = 1 + max(getHeight(node->left_), getHeight(node->right_));
    new_root->height_ = 1 + max(getHeight(new_root->left_), getHeight(new_root->right_));

    return new_root;
}
