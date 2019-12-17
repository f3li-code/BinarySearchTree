#include "gtest/gtest.h"
#include "../header/BSTree.h"

TEST(insert, t1) {
    BSTree bst;
    bst.insert("hello");
    bst.insert("hello");
    bst.insert("wassup");
    bst.preOrder();
}