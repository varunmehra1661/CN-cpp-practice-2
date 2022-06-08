#include <bits/stdc++.h>
using namespace std;
#include "classTreeNode.h"

template <typename T>
class Pair
{
public:
    T left;
    T right;
};

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

// treeNode<int> *minNode(treeNode<int> *root)
// {
//     treeNode<int> *min = new treeNode<int>(root->data);

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         treeNode<int> *child = minNode(root->children[i]);
//         if (child->data < min->data)
//             min = child;
//     }

//     return min;
// }

// treeNode<int> *maxNode(treeNode<int> *root)
// {
//     treeNode<int> *max = new treeNode<int>(root->data);

//     for (int i = 0; i < root->children.size(); i++)
//     {
//         treeNode<int> *child = maxNode(root->children[i]);
//         if (child->data > max->data)
//             max = child;
//     }

//     return max;
// }

Pair<int> minMax(treeNode<int> *root)
{
    if (!root)
    {
        Pair<int> p;
        p.left = p.right = 0;
        return p;
    }

    if (root->children.size() == 0)
    {
        Pair<int> p;
        p.left = p.right = root->data;
        return p;
    }
    Pair<int> p;
    p.left = p.right = root->data;
    vector<int> anss;
    anss.push_back(root->data);

    for (int i = 0; i < root->children.size(); i++)
    {
        anss.push_back(root->children[i]->data);
    }

    p.left = *max_element(anss.begin(), anss.end());
    p.right = *min_element(anss.begin(), anss.end());
    return p;
}

// 1 3 2 3 4 2 5 6 1 7 0 0 0 0

int main()
{
    treeNode<int> *root = takeInputLevel();
    print(root);
    cout << endl;
    // treeNode<int> *max = maxNode(root);
    // cout << max->data;
    // cout << endl;
    // treeNode<int> *min = minNode(root);
    // cout << min->data;
    Pair<int> p = minMax(root);
    cout << p.left << " " << p.right;
}