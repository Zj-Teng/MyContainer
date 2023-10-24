//
// Created by Teng on 2023/10/2.
//

#include "my_list.h"
#include "iostream"
#include "exception"

using namespace std;

ListNode::ListNode(int val, ListNode *prev, ListNode *next) {
    val_ = val;
    prev_ = prev;
    next_ = next;
}

ListNode::~ListNode() {
    val_ = 0;
    prev_ = nullptr;
    next_ = nullptr;
}

void ListNode::setValue(int val) {
    val_ = val;
}

int ListNode::getValue() const {
    return val_;
}

ListNode *ListNode::getNext() {
    return next_;
}

ListNode *ListNode::getPrev() {
    return prev_;
}

void ListNode::setNext(ListNode *node) {
    next_ = node;
}

void ListNode::setPrev(ListNode *node) {
    prev_ = node;
}


MyList::~MyList() {
    while (head_ != nullptr){
        ListNode *next = head_->getNext();
        delete head_;
        head_ = nullptr;
        head_ = next;
    }
}

int MyList::getSize() const {
    return size_;
}

ListNode *MyList::getHead() {
    return head_;
}

ListNode *MyList::getBack() {
    return back_;
}

void MyList::setHead(ListNode *ln) {
    head_ = ln;
}

void MyList::setBack(ListNode *ln) {
    back_ = ln;
}

void MyList::push_back(int val) {
    auto ln = new ListNode(val, nullptr, nullptr);
    if (empty()) {
        head_ = ln;
        back_ = ln;
        size_ ++;
        return ;
    }

    back_->setNext(ln);
    ln->setPrev(back_);
    setBack(ln);
    size_ ++;
}

bool MyList::empty() const {
    return size_ == 0;
}

int MyList::at(int index) {
    ListNode *start = head_;
    if (index >= size_) throw out_of_range("overflow");
    for (int cnt = 0; cnt < index; cnt ++){
        start = start->getNext();
    }

    return start->getValue();
}

void MyList::pop_back() {
    ListNode *end = back_;
    setBack(back_->getPrev());
    delete end;

    size_ --;
}

void MyList::push_front(int val) {
    auto ln = new ListNode(val, nullptr, nullptr);
    if (empty()) {
        head_ = ln;
        back_ = ln;
        size_ ++;
        return ;
    }

    ln->setNext(head_);;
    setHead(ln);
    size_ ++;
}

void MyList::pop_front() {
    ListNode *start = head_;
    setHead(head_->getNext());
    delete start;

    size_ --;
}

void MyList::reverse() {
    ListNode *tmp = head_;
    head_ = back_;
    back_ = tmp;
}
