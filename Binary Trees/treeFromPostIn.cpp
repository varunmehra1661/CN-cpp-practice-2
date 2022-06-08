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

binaryTree<int> *buildBTHelper(int *in, int *po, int inS, int inE, int poS, int poE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = po[poE];
    binaryTree<int> *root = new binaryTree<int>(rootData);
    int rootIndexIn = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndexIn = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndexIn - 1;
    int lPoS = poS;
    int lPoE = (lInE - lInS) + lPoS;

    int rInS = rootIndexIn + 1;
    int rInE = inE;
    int rPoS = lPoE + 1;
    int rPoE = poE - 1;

    root->left = buildBTHelper(in, po, lInS, lInE, lPoS, lPoE);
    root->right = buildBTHelper(in, po, rInS, rInE, rPoS, rPoE);
    return root;
}

binaryTree<int> *buildBT(int *in, int *po, int size)
{
    return buildBTHelper(in, po, 0, size - 1, 0, size - 1);
}

// 1 2 3 4 5 6 7 -1 -1 -1 10 -1 -1 12 11 -1 -1 -1 -1 -1 -1

int main()
{
    int in[] = {4, 2, 5, 1, 8, 6, 9, 3};
    int po[] = {4, 5, 2, 8, 9, 6, 3, 1};
    binaryTree<int> *root = buildBT(in, po, 8);
    printLevel(root);
    // binaryTree<int> *root = takeInput();
    // printLevel(root);
}