#include <bits/stdc++.h>
using namespace std;
#include "classTreeNode.h"

treeNode<int> *takeInputLevel()
{
    int rootData;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *fr = pendingNodes.front();
        pendingNodes.pop();
        int childNum;
        cout << "Number of children of " << fr->data << "::";
        cin >> childNum;
        for (int i = 0; i < childNum; i++)
        {
            int childData;
            cin >> childData;
            treeNode<int> *child = new treeNode<int>(childData);
            fr->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void print(treeNode<int> *root)
{
    if (!root)
    {
        return;
    }
    queue<treeNode<int> *> pendingQ;
    pendingQ.push(root);
    while (pendingQ.size() != 0)
    {
        treeNode<int> *fr = pendingQ.front();
        cout << fr->data << " : ";
        pendingQ.pop();
        for (int i = 0; i < root->children.size(); i++)
        {
            pendingQ.push(root->children[i]);
            if (root->children.size() - 1 != i)
            {
                cout << root->children[i]->data << " , ";
            }
            else
            {
                cout << root->children[i]->data;
            }
        }
        root = pendingQ.front();
        cout << endl;
    }
}

int main()
{
    treeNode<int> *root = takeInputLevel();
    print(root);
}