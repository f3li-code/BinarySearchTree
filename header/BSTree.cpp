#include "BSTree.h"
#include <string>
#include <iostream>
using namespace std;

BSTree::BSTree()
{
    root = nullptr;
}

bool BSTree::empty(){
    return (root == nullptr);
}

Node* BSTree::findPos(const string& str) const{
    Node* cur = root;
    Node* newNode = new Node(str);
    while (cur != nullptr){
        if (newNode->compare(cur) == 0){//FOUND
            return cur;
        }
        else if (newNode->compare(cur) < 0){
            cur = cur->getLeft();
        }
        else {
            cur = cur->getRight();
        }
    }
    return nullptr;
}

bool BSTree::search(const string& str) const{
    return search(root, str);
}
bool BSTree::search(Node* n, const string& str) const{
    if (n != nullptr){
        if (n->getString() == str){
            return true;
        }
        else if (n->getString().compare(str) < 0){
            return search(n->getRight(), str);
        }
        else {
            return search(n->getLeft(), str);
        }
    }
    return false;
}
void BSTree::insert(const string & str){
    Node* insertNode = new Node(str);
    Node* cur = root;
    if (empty()){
        root = insertNode;
        return;
    }
    if (search(str)){
        Node* dup = findPos(str);
        dup->incrementCount();
        return;
    }
    while (cur != nullptr){
        if (insertNode->compare(cur) < 0){
            if (cur->getLeft() == nullptr){
                cur->setLeft(insertNode);
                return;
            }
            else {
                cur = cur->getLeft();
            }
        }//insert left
        else if (insertNode->compare(cur) > 0){
            if (cur->getRight() == nullptr){
                cur->setRight(insertNode);
                return;
            }
            else {
                cur = cur->getRight();
            }
        } //insert right
    }
}

void BSTree::inOrder() const{
    inOrder(root);
    cout << endl;
}
void BSTree::inOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    inOrder(n->getLeft());
    n->print();
    inOrder(n->getRight());
}

void BSTree::preOrder() const{
    preOrder(root);
    cout << endl;
}
void BSTree::preOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    n->print();
    preOrder(n->getLeft());
    preOrder(n->getRight());
}

void BSTree::postOrder()const{
    postOrder(root);
    cout << endl;
}
void BSTree::postOrder(Node* n) const{
    if (n == nullptr){
        return;
    }
    postOrder(n->getLeft());
    postOrder(n->getRight());
    n->print();
}

string BSTree::smallest() const{
    Node* cur = root;
    if (root != nullptr){
    while (cur->getLeft() != nullptr){
        cur = cur->getLeft();
    }
    return cur->getString();
    }
    else {
        return "";
    }
}
string BSTree::largest() const{
    Node* cur = root;
    if (root != nullptr){
    while (cur->getRight() != nullptr){
        cur = cur->getRight();
    }
    return cur->getString();
    }
    else {
        return "";
    }
}

int BSTree::height(const string &str) const{//https://www.youtube.com/watch?v=_O-mK2g_jhI
    if (search(str)){
        return height(findPos(str)) - 1;
    }
    else {
        return -1;
    }
}
int BSTree::height(Node* n) const{
    if (n == nullptr){
        return 0;
    }
    int left = height(n->getLeft());
    int right = height(n->getRight());
    int h;
    if (left > right){
        h = left + 1;
    }
    else {
        h = right + 1;
    }
    return h;
}

Node* BSTree::findPar(const string & str) const{ //assume string exists in the Tree
    //private
    Node* prev = root;
    Node* cur = nullptr;
    Node* tar = new Node(str);
    if (tar->compare(root)== 0){
        //if remove root node , root's parent = NULL
    }
    else if (tar->compare(root) < 0){
        cur = root->getLeft();
    }
    else{
        cur = root->getRight();
    }
    while (cur != nullptr){
        if (cur->compare(tar) == 0){
            return prev;
        }
        else if (cur->compare(tar) < 0){
            prev = cur;
            cur = cur->getRight();
        }
        else {
            prev = cur;
            cur = cur->getLeft();
        }
    }
    return prev;
}
Node* BSTree::findSuccessor(Node* tar) const{
    //private // Leftmost of TAR's Right node
    Node* suc = tar->getRight();
    while (suc->getLeft() != nullptr){
        suc = suc->getLeft();
    }
    return suc;
}
void BSTree::remove(const string & str){
    if (search(str)){
    Node* tar = findPos(str);
    Node* par = findPar(str);
    remove(par, tar);
    }
    return;
}
void BSTree::remove (Node* par, Node* tar){//https://www.youtube.com/watch?v=gcULXE7ViZw
    //private
    if (tar->getCount() > 1){
        tar->decrementCount();
        return;
    }
    if (tar == root){
        if (root->getLeft() != nullptr && root->getRight() != nullptr){
            Node* suc = findSuccessor(tar);
            root->setString(suc->getString());
            Node* par = findPar(suc->getString());//FIXME IMPLEMENT A GETPARENT FUNCTION THAT TAKES PTR as ARG
            remove(par, suc);
            return;
        }
        else if (root->getLeft()!= nullptr && root->getRight() == nullptr){
            root = root->getLeft();
            return;
        }
        else {
            root = root->getRight();
            return;
        }
    }

    if (tar->getLeft() == nullptr && tar->getRight() == nullptr){ //LEAF
        if (par->getLeft() == tar){
            delete tar;
            par->setLeft(nullptr);
            return;
        }
        else {
            delete tar;
            par->setRight(nullptr);
            return;
        }
    }
    else if (tar->getLeft() == nullptr && tar->getRight() != nullptr){//ONLY RIGHT
        if (par->getRight() == tar){
            par->setRight(tar->getRight());
            delete tar;
            return;
        }
        else {
            par->setLeft(tar->getRight());
            delete tar;
            return;
        }
    }
    else if (tar->getLeft() != nullptr && tar->getRight() == nullptr){//ONLY LEFT
        if (par->getRight() == tar){
            par->setRight(tar->getLeft());
            delete tar;
            return;
        }
        else {
            par->setLeft(tar->getLeft());
            delete tar;
            return;
        }
    }
    else if (tar->getLeft() != nullptr && tar->getRight() != nullptr){//BOTH CHILDREN
        Node* suc = findSuccessor(tar);
        string tmpStr = "";
        tmpStr = suc->getString();
        tar->setString(suc->getString());
        suc->setString(tmpStr);
        remove(tar->getRight(), suc);
        return;
    }
}
