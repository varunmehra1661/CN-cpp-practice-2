#include <bits/stdc++.h>
#include "classBT.h"
using namespace std;

binaryTree<int> *takeInput()
{
    int rootData;
    // cout << "Enter root data :: ";
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    binaryTree<int> *root = new binaryTree<int>(rootData);
    queue<binaryTree<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        binaryTree<int> *fr = pendingQ.front();
        pendingQ.pop();

        // left child
        // cout << "Enter the left child of " << fr->data << " :: ";
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            binaryTree<int> *leftNode = new binaryTree<int>(leftData);
            fr->left = leftNode;
            pendingQ.push(leftNode);
        }

        // right child
        // cout << "Enter the right child of " << fr->data << " :: ";
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            binaryTree<int> *rightNode = new binaryTree<int>(rightData);
            fr->right = rightNode;
            pendingQ.push(rightNode);
        }
    }
    return root;
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

bool isPresent(binaryTree<int> *root, int x)
{
    if (!root)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    bool leftSearch = isPresent(root->left, x);
    bool rightSearch = isPresent(root->right, x);

    return leftSearch || rightSearch;
}

// 1 2 3 4 5 6 7 -1 -1 -1 10 -1 -1 12 11 -1 -1 -1 -1 -1 -1

int main()
{
    binaryTree<int> *root = takeInput();
    printLevel(root);
    cout << endl;
    cout << isPresent(root, 17);
}