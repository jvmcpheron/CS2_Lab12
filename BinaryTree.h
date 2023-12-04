//
// Created by Richard Maclin on 11/9/23.
//
#ifndef BINARYTREES_BINARYTREE_H
#define BINARYTREES_BINARYTREE_H
#include <iostream>
namespace std {
class BinaryNode {
private:
int data;
BinaryNode *left;
BinaryNode *right;
BinaryNode() {}
public:
BinaryNode(int d, BinaryNode *lft = nullptr, BinaryNode *rgt = nullptr) {
data = d;
left = lft;
right = rgt;
}
int getData() { return data; }
BinaryNode *getLeft() { return left; }
BinaryNode *getRight() { return right; }
void setData(int d) { data = d; }
void setLeft(BinaryNode *p) { left = p; }
void setRight(BinaryNode *p) { right = p; }
int compare(BinaryNode *p) { return p->data - data; }
int compare(int d) { return d - data; }
void doPrintFlat(ostream &out);
void doPrintInOrder(ostream &out, int indent = 0);
void doPrintPreOrder(ostream &out, int indent = 0);
void doPrintPostOrder(ostream &out, int indent = 0);
};
class BinaryTree {
private:
BinaryNode *root;
public:
BinaryTree() { root = nullptr; }
BinaryNode* getRoot() { return root; }
bool isEmpty() { return (root == nullptr); }
BinaryNode *find(int d);
void insert(int d);
bool remove(int d);
void printFlat(ostream &out);
void printInOrder(ostream &out);
void printPreOrder(ostream &out);
void printPostOrder(ostream &out);
};
} // std
#endif //BINARYTREES_BINARYTREE_H
