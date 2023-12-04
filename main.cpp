//
// Created by Richard Maclin on 11/9/23.
//

#include "BinaryTree.h"
#include <iostream>>
#include <fstream>
#include <iomanip>
#include <memory>

using namespace std;


    BinaryNode *doFind(int d, BinaryNode *curr) {
        if (curr == nullptr) {
            return nullptr;
        }
        cout << "Looking at " << curr->getData() << endl;
        int cmp = curr->compare(d);
        if (cmp == 0) {
            return curr;
        }
        else {
            if (cmp < 0) {
                return doFind(d,curr->getLeft());
            }
            else {
                return doFind(d,curr->getRight());
            }
        }
    }

    BinaryNode *BinaryTree::find(int d) {
        return doFind(d,root);
    }

    BinaryNode *doInsert(BinaryNode *curr, int d) {
        if (curr == NULL) {
            return new BinaryNode(d);
        }
        cout << "curr is " << curr->getData() << endl;
        int cmp = curr->compare(d);
        if (cmp <= 0) {
            curr->setLeft(doInsert(curr->getLeft(),d));
        }
        else {
            curr->setRight(doInsert(curr->getRight(),d));
        }
        return curr;
    }

    void BinaryTree::insert(int d) {
        if (root == nullptr) {
            root = new BinaryNode(d);
            return;
        }
        int cmp = root->compare(d);
        if (cmp <= 0) {
            root->setLeft(doInsert(root->getLeft(),d));
        }
        else {
            root->setRight(doInsert(root->getRight(),d));
        }
    }

    BinaryNode *removeNextHighestValue(BinaryNode *curr, int &nextD) {
        if (curr->getLeft() == nullptr) {
            BinaryNode *discard = curr;
            nextD = curr->getData();
            if (curr->getRight() == nullptr) {
                delete discard;
                return nullptr;
            }
            else {
                BinaryNode *rightC = curr->getRight();
                delete discard;
                return rightC;
            }
        }
        else {
            curr->setLeft(removeNextHighestValue(curr->getLeft(),nextD));
            return curr;
        }
    }

    BinaryNode *doRemove(BinaryNode *curr, int d, bool &found) {
        if (curr == nullptr) {
            return nullptr;
        }
        int cmp = curr->compare(d);
        if (cmp == 0) {
            found = true;
            if (curr->getLeft() == nullptr) {
                if (curr->getRight() == nullptr) {
                    delete curr;
                    return nullptr;
                }
                else {
                    BinaryNode *rightC = curr->getRight();
                    delete curr;
                    return rightC;
                }
            }
            else {
                if (curr->getRight() == nullptr) {
                    BinaryNode *leftC = curr->getLeft();
                    delete curr;
                    return leftC;
                }
                else {
                    int nextD;
                    curr->setRight(removeNextHighestValue(curr->getRight(),nextD));
                    curr->setData(nextD);
                    return curr;
                }
            }
        }
        else {
            if (cmp < 0) {
                curr->setLeft(doRemove(curr->getLeft(),d,found));
            }
            else {
                curr->setRight(doRemove(curr->getRight(),d,found));
            }
            return curr;
        }
    }

    bool BinaryTree::remove(int d) {
        if (root == nullptr) {
            return false;
        }
        bool found = false;
        root = doRemove(root,d,found);
        return found;
    }

    void BinaryNode::doPrintFlat(ostream &out) {
        if (left != nullptr) left->doPrintFlat(out);
        out << data << " ";
        if (right != nullptr) right->doPrintFlat(out);
    }

    void BinaryTree::printFlat(ostream &out) {
        if (root != nullptr) {
            root->doPrintFlat(out);
        }
        out << endl;
    }

    void BinaryNode::doPrintInOrder(ostream &out, int indent) {
        if (right != nullptr) right->doPrintInOrder(out,indent+1);
        out << setw(indent*3) << " ";
        out << data << "\n";
        if (left != nullptr) left->doPrintInOrder(out,indent+1);
    }

    void BinaryTree::printInOrder(ostream &out) {
        if (root != nullptr) {
            root->doPrintInOrder(out);
        }
        out << endl;
    }

    void BinaryNode::doPrintPreOrder(ostream &out, int indent) {
        out << setw(indent*3) << " ";
        out << data << "\n";
        if (right != nullptr) right->doPrintPreOrder(out,indent+1);
        if (left != nullptr) left->doPrintPreOrder(out,indent+1);
    }

    void BinaryTree::printPreOrder(ostream &out) {
        if (root != nullptr) {
            root->doPrintPreOrder(out,0);
        }
        out << endl;
    }

    void BinaryNode::doPrintPostOrder(ostream &out, int indent) {
        if (right != nullptr) right->doPrintPostOrder(out,indent+1);
        if (left != nullptr) left->doPrintPostOrder(out,indent+1);
        out << setw(indent*3) << " ";
        out << data << "\n";
    }

    void BinaryTree::printPostOrder(ostream &out) {
        root->doPrintPostOrder(out,0);
        out << endl;
    }

    




void traverse(BinaryNode *n, ostream &out) {
    if (n != nullptr) {
        out << "Pre " << n->getData() << " ";
        traverse(n->getLeft(), out);
        out << "In " << n->getData() << " ";
        traverse(n->getRight(), out);
        out << "Post " << n->getData() << " ";
    }
}
void processCommands(bool fromFile, istream& inS) {
    BinaryTree tree;
    string option;
    do {
        int value;
        if (!fromFile) cout << "Commands: I)nsert, R)emove, F)ind, \n     PF)rintflat, printIN)order, printPRE)order printPOST)order T)raverse Q)uit: ";
        inS >> option;
        if (option.compare("I") == 0) {
            if (!fromFile) cout << "Insert value: ";
            inS >> value;
            if (fromFile) cout << "Inserting " << value << endl;
            tree.insert(value);
        }
        else if (option.compare("R") == 0) {
            if (!fromFile) cout << "Remove value: ";
            inS >> value;
            if (fromFile) cout << "Removing value " << value << endl;
            if (tree.remove(value)) {
                cout << "Successfully removed\n";
            }
            else {
                cout << "Not removed\n";
            }
        }
        else if (option.compare("F") == 0) {
            if (!fromFile) cout << "Find value: ";
            inS >> value;
            if (fromFile) cout << "Finding " << value << endl;
            if (tree.find(value)) {
                cout << "Found\n";
            }
            else {
                cout << "Not found\n";
            }
        }
        else if (option.compare("PF") == 0) {
            if (fromFile) cout << "Print Flat:\n";
            tree.printFlat(cout);
        }
        else if (option.compare("IN") == 0) {
            if (fromFile) cout << "Print In Order:\n";
            tree.printInOrder(cout);
        }
        else if (option.compare("PRE") == 0) {
            if (fromFile) cout << "Print PreOrder:\n";
            tree.printPreOrder(cout);
        }
        else if (option.compare("POST") == 0) {
            if (fromFile) cout << "Print PostOrder:\n";
            tree.printPostOrder(cout);
        }
        else if (option.compare("T") == 0) {
            if (fromFile) cout << "Traverse:\n";
            traverse(tree.getRoot(),cout);
        }
        else if (option.compare("Q") != 0) {
            cout << "Unknown option " << option << endl;
        }
    } while (option.compare("Q") != 0);
}

int main() {
    string option;
    string fileName;

    cout << "Read from file (Y/N)? ";
    cin >> option;
    if (option.compare("Y") == 0) {
        cout << "Filename: ";
        cin >> fileName;
        ifstream inF(fileName);
        if (inF.good()) {
            processCommands(true,inF);
        }
    }
    else {
        processCommands(false,cin);
    }


    return 0;
}
