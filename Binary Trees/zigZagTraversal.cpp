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

void zigZagOrder(binaryTree<int> *root)
{
    if (!root)
        return;

    stack<binaryTree<int> *> s1;
    stack<binaryTree<int> *> s2;

    s1.push(root);

    while (!s1.empty() && !s1.empty())
    {
        while (!s1.empty())
        {
            binaryTree<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";

            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->right);
        }

        cout << endl;

        while (!s2.empty())
        {
            binaryTree<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";

            if (top->right)
                s1.push(top->right);
            if (top->left)
                s1.push(top->left);
        }
        cout << endl;
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 10 -1 -1 12 11 -1 -1 -1 -1 -1 -1
// 1 2 3 4 5 6 7 -1 -1 -1 8 -1 9 -1 -1 -1 -1 10 -1

int main()
{
    binaryTree<int> *root = takeInput();
    // printLevel(root);
    cout << endl;
    zigZagOrder(root);
}