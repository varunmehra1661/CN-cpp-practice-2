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

void insertDuplicateNode(binaryTree<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;

    binaryTree<int> *duplicate = new binaryTree<int>(root->data);
    duplicate->left = root->left;
    root->left = duplicate;

    insertDuplicateNode(duplicate->left);
    insertDuplicateNode(root->right);
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input) / sizeof(int);
    binaryTree<int> *root = constructTree(input, n);
    printLevel(root);
    cout << endl;
    insertDuplicateNode(root);
    printLevel(root);
}
