#include <bits/stdc++.h>
#include "C:\Users\Varun Mehra\OneDrive\Desktop\prog files\April prac c++\Binary Trees\classBT.h"
using namespace std;

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

binaryTree<int> *tree(int input[], int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;

    binaryTree<int> *root = new binaryTree<int>(input[mid]);

    root->left = tree(input, s, mid - 1);
    root->right = tree(input, mid + 1, e);
    return root;
}
binaryTree<int> *constructTree(int *input, int n)
{

    return tree(input, 0, n - 1);
}

binaryTree<int> *isPresentAt(binaryTree<int> *root, int data)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == data)
    {
        return root;
    }
    if (root->data > data)
    {
        isPresentAt(root->left, data);
    }
    if (root->data < data)
    {
        isPresentAt(root->right, data);
    }
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input) / sizeof(int);
    binaryTree<int> *root = constructTree(input, n);
    printLevel(root);
    binaryTree<int> *ans = isPresentAt(root, 8);
    cout << ans->data;
}
