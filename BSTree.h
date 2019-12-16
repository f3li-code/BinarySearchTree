#ifndef BSTREE_H
#define BSTREE_H
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;


class BSTree
{
    public:
        BSTree();//
        void insert(const string &);//
        bool search(const string &) const;//
        string largest() const;//
        string smallest() const;//
        int height(const string &) const;//
        void remove(const string &);
        void preOrder() const;//
        void inOrder() const;//
        void postOrder() const;//
        bool empty();//NR

    private:
        Node* root;
        int height (Node*) const;
        void postOrder(Node*) const;
        void preOrder(Node*) const;
        void inOrder(Node*) const;
        bool search(Node*, const string&) const;
        void remove(Node* par, Node* tar);
        Node* findSuccessor(Node* tar) const;
        Node* findPos(const string&) const;//
        Node* findPar(const string&) const;

};

#endif // BSTREE_H
