#include <bits/stdc++.h>
using namespace std;
template <typename T>

class binaryTree
{
public:
    T data;
    binaryTree<T> *left;
    binaryTree<T> *right;

    binaryTree(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTree()
    {
        delete left;
        delete right;
    }
};