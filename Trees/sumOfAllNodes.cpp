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
        // cout << "Number of children of " << fr->data << "::";
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

int sum(treeNode<int> *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + sum(root->children[i]);
    }
    return ans;
}
// 1 3 2 3 4 2 5 6 1 7 0 0 0 0

int main()
{
    treeNode<int> *root = takeInputLevel();
    print(root);
    cout << endl;
    cout << sum(root);
}