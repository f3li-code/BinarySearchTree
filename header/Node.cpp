#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

Node::Node()
{
    str = "";
    count = 1;
    left = nullptr;
    right = nullptr;
}
Node::Node(string str){
    this->str = str;
    count = 1;
    left = nullptr;
    right = nullptr;
}
string Node::getString() const{
    return str;
}
int Node::getCount() const{
    return count;
}
Node* Node::getLeft() const{
    return left;
}
Node* Node::getRight() const{
    return right;
}
void Node::setString(string str){
    this->str = str;
    return;
}
void Node::incrementCount(){
    count++;
    return;
}

void Node::decrementCount(){
    count--;
    return;
}
void Node::setLeft(Node* left){
    this->left = left;
    return;
}
void Node::setRight(Node* right){
    this->right = right;
    return;
}
int Node::compare(Node* rhs) const{
    return ((this->getString()).compare(rhs->getString()));
}

void Node::print() const{
    cout << str << "(" << count << "), ";
    //goodbye(1), Hello World(3),
}
