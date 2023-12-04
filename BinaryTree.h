//
// Created by Richard Maclin on 11/9/23.
//
#ifndef BINARYTREES_BINARYTREE_H
#define BINARYTREES_BINARYTREE_H
#include <iostream>
#include <memory>

namespace std {
class BinaryNode {
private:
int data;
shared_ptr<BinaryNode> left;
shared_ptr<BinaryNode>right;
BinaryNode() {}
public:
~BinaryNode() ;
BinaryNode(int d, shared_ptr<BinaryNode>lft = nullptr, shared_ptr<BinaryNode>rgt = nullptr) {
data = d;
left = lft;
right = rgt;
}
int getData() { return data; }
shared_ptr<BinaryNode>getLeft() { return left; }
shared_ptr<BinaryNode>getRight() { return right; }
void setData(int d) { data = d; }
void setLeft(shared_ptr<BinaryNode>p) { left = p; }
void setRight(shared_ptr<BinaryNode>p) { right = p; }
int compare(shared_ptr<BinaryNode>p) { return p->data - data; }
int compare(int d) { return d - data; }
void doPrintFlat(ostream &out);
void doPrintInOrder(ostream &out, int indent = 0);
void doPrintPreOrder(ostream &out, int indent = 0);
void doPrintPostOrder(ostream &out, int indent = 0);
};
class BinaryTree {
private:
shared_ptr<BinaryNode>root;
public:
BinaryTree() { root = nullptr; }
shared_ptr<BinaryNode> getRoot() { return root; }
bool isEmpty() { return (root == nullptr); }
shared_ptr<BinaryNode>find(int d);
void insert(int d);
bool remove(int d);
void printFlat(ostream &out);
void printInOrder(ostream &out);
void printPreOrder(ostream &out);
void printPostOrder(ostream &out);
};
} // std
#endif //BINARYTREES_BINARYTREE_H
