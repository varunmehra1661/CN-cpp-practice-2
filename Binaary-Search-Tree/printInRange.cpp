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

void elementsInRangeK1K2(binaryTree<int> *root, int k1, int k2)
{

    if (NULL == root)
        return;

    if (k1 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);

    if (k1 <= root->data && k2 >= root->data)
        cout << root->data << " ";

    if (k2 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input) / sizeof(int);
    binaryTree<int> *root = constructTree(input, n);
    printLevel(root);
    elementsInRangeK1K2(root, 3, 8);
}
