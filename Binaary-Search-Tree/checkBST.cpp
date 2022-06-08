#include <bits/stdc++.h>
#include "C:\Users\Varun Mehra\OneDrive\Desktop\prog files\April prac c++\Binary Trees\classBT.h"
using namespace std;

class isBSTReturn
{
public:
    bool isBST;
    int maxi;
    int mini;
};

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

int maximum(binaryTree<int> *root)
{
    if (!root)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(binaryTree<int> *root)
{
    if (!root)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

bool checkBST1(binaryTree<int> *root)
{
    if (!root)
    {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST1(root->left) && checkBST1(root->right);
    return output;
}

isBSTReturn checkBST2(binaryTree<int> *root)
{
    if (!root)
    {
        isBSTReturn output;
        output.isBST = true;
        output.maxi = INT_MIN;
        output.mini = INT_MAX;
        return output;
    }

    isBSTReturn leftOutput = checkBST2(root->left);
    isBSTReturn rightOutput = checkBST2(root->right);
    int maximum = max(root->data, max(leftOutput.maxi, rightOutput.maxi));
    int minimum = min(root->data, min(leftOutput.mini, rightOutput.mini));
    bool isFinalBST = (leftOutput.maxi < root->data) && (rightOutput.mini >= root->data) && (leftOutput.isBST) && (rightOutput.isBST);
    isBSTReturn output;
    output.maxi = maximum;
    output.mini = minimum;
    output.isBST = isFinalBST;
    return output;
}

bool checkBST3(binaryTree<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (!root)
    {
        return true;
    }
    if (root->data < min or root->data > max)
    {
        return false;
    }

    bool isleft = (root->left, min, root->data - 1);
    bool isright = (root->right, root->data, max);
    return isleft && isright;
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input) / sizeof(int);
    binaryTree<int> *root = constructTree(input, n);
    printLevel(root);
    cout << checkBST1(root);
    cout << endl;
    cout << "TRIPLET SOLVE:::-" << endl;
    isBSTReturn output = checkBST2(root);
    cout << output.isBST;
}
