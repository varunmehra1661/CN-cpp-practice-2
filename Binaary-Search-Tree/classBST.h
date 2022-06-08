#include <bits/stdc++.h>
#include "C:\Users\Varun Mehra\OneDrive\Desktop\prog files\April prac c++\Binary Trees\classBT.h"
using namespace std;

class BST
{
    binaryTree<int> *root;

    bool hasData(binaryTree<int> *node, int data)
    {
        if (!node)
        {
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data < root->data)
        {
            return hasData(node->left, data);
        }
        if (data > root->data)
        {
            return hasData(node->right, data);
        }
    }

    binaryTree<int> *insertData(binaryTree<int> *node, int data)
    {
        if (!node)
        {
            binaryTree<int> *newNode = new binaryTree<int>(data);
            return newNode;
        }

        if (data < node->data)
        {
            node->left = insertData(node->left, data);
        }
        if (data > node->data)
        {
            node->right = insertData(node->right, data);
        }
        return node;
    }

    binaryTree<int> *deleteData(binaryTree<int> *node, int data)
    {
        if (!node)
        {
            return NULL;
        }

        if (data > node->data)
        {
            node->right = deleteData(node->right, data);
            return node;
        }
        else if (data < node->data)
        {
            node->left = deleteData(node->left, data);
            return node;
        }

        else
        {
            if (!node->left and !node->right)
            {
                delete node;
                return NULL;
            }
            else if (!node->right)
            {
                binaryTree<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (!node->left)
            {
                binaryTree<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            binaryTree<int> *minNode = node->right;
            while (!minNode->left)
            {
                minNode = minNode->left;
            }
            int rightMin = minNode->data;
            node->data = rightMin;
            node->right = deleteData(node->right, rightMin);
            return node;
        }
    }

    void printLevel(binaryTree<int> *root)
    {
        if (!root)
        {
            return;
        }

        queue<binaryTree<int> *> pendingNodes;
        pendingNodes.push(root);
        while (pendingNodes.size() != 0)
        {
            binaryTree<int> *fr = pendingNodes.front();
            cout << fr->data << " ::: ";
            pendingNodes.pop();

            if (root->left != NULL)
            {
                cout << "L :: " << fr->left->data << " , ";
                pendingNodes.push(fr->left);
            }
            else
            {
                cout << "L : "
                     << "-1"
                     << " , ";
            }

            if (root->right != NULL)
            {
                cout << "R :: " << fr->right->data << " , ";
                pendingNodes.push(fr->right);
            }
            else
            {
                cout << "R : "
                     << "-1";
            }

            cout << endl;
            root = pendingNodes.front();
        }
    }

public:
    // constructor
    BST()
    {
        root = NULL;
    }

    // destructor
    ~BST()
    {
        delete root;
    }

    void print()
    {
        printLevel(root);
    }

    void deleteData(int data)
    {
        root = deleteData(root, data);
    }

    void insertData(int data)
    {
        this->root = insertData(this->root, data);
    }

    bool hasData(int data)
    {
        return hasData(root, data);
    }
};