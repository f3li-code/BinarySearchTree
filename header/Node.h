#ifndef NODE_H
#define NODE_H
#include <string>
#include <iostream>
using namespace std;


class Node
{
    public:
        Node();//
        Node(string str);
        string getString() const;
        int getCount() const;
        Node* getLeft() const;
        Node* getRight() const;
        void setString(string str);
        void incrementCount();
        void decrementCount();
        void setLeft(Node* left);
        void setRight(Node* right);
        int compare(Node* rhs) const;
        void print() const;

    private:
        string str;
        int count;
        Node* left;
        Node* right;
};

#endif // NODE_H
