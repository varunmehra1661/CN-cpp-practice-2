#include <bits/stdc++.h>
#include "classBT.h"
using namespace std;
template <typename T>

class Pair
{
public:
    T left;
    T right;
};

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

// int height(binaryTree<int> *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     int lH = height(root->left);
//     int rH = height(root->right);
//     return max(rH, lH) + 1;
// }

// int diameter(binaryTree<int> *root)
// {
//     if (!root)
//     {
//         return 0;
//     }
//     int op1 = height(root->left) + height(root->right);
//     int op2 = diameter(root->left);
//     int op3 = diameter(root->right);
//     return max(op1, max(op2, op3));
// }

Pair<int> heightDiameterBetter(binaryTree<int> *root)
{
    if (!root)
    {
        Pair<int> p;
        p.left = p.right = 0;
        return p;
    }

    Pair<int> leftAns = heightDiameterBetter(root->left);
    Pair<int> rightAns = heightDiameterBetter(root->right);

    int ld = leftAns.right;
    int lh = leftAns.left;
    int rd = rightAns.right;
    int rh = rightAns.left;

    int height = 1 + max(rh, lh);
    int diameter = max(rh + lh, max(rd, ld));
    Pair<int> p;
    p.left = height;
    p.right = diameter;
    return p;
}

// 1 2 3 4 5 6 7 -1 -1 -1 10 -1 -1 12 11 -1 -1 -1 -1 -1 -1

int main()
{
    binaryTree<int> *root = takeInput();
    printLevel(root);
    cout << endl;
    Pair<int> heiDiam = heightDiameterBetter(root);
    // cout << diam;
    cout << max(heiDiam.left, heiDiam.right);
    // cout << height(root);
}