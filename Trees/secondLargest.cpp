#include <bits/stdc++.h>
using namespace std;
#include "classTreeNode.h"
// template <typename T>
class helper
{
public:
    treeNode<int> *m;
    treeNode<int> *sm;

    helper(treeNode<int> *m, treeNode<int> *sm)
    {
        this->m = m;
        this->sm = sm;
    }
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

// Pair<int> maxSmax(treeNode<int> *root)
// {
//     Pair<int> ans;
//     if (!root)
//     {
//         ans.max = NULL;
//         ans.smax = NULL;
//         return ans;
//     }

//     if (root->children.size() == 0)
//     {
//         ans.max = root->data;
//         ans.smax = NULL;
//         return ans;
//     }

//     // Pair<int> temp;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         Pair<int> temp = maxSmax(root->children[i]);
//         if (ans.max < temp.max and ans.smax == NULL and temp.smax == NULL)
//         {
//             int x = ans.max;
//             ans.max = temp.max;
//             ans.smax = x;
//         }
//         else
//         {
//             ans.smax = temp.max;
//         }

//         if (ans.max < temp.max and ans.smax == NULL and temp.smax != NULL)
//         {
//             int x = ans.max;
//             ans.max = temp.max;
//             ans.smax = max(x, temp.smax);
//         }
//         else
//         {
//             ans.smax = max(ans.smax, temp.max);
//         }

//         if (ans.max < temp.max and ans.smax != NULL and temp.smax == NULL)
//         {
//             int x = ans.max;
//             ans.max = temp.max;
//             ans.smax = max(x, temp.smax);
//         }
//         else
//         {
//             ans.smax = max(ans.smax, temp.max);
//         }

//         if (ans.max < temp.max and ans.smax != NULL and temp.smax != NULL)
//         {
//             int x = ans.max;
//             ans.max = temp.max;
//             ans.smax = max(x, temp.smax);
//         }
//         else
//         {
//             ans.smax = max(ans.smax, temp.max);
//         }
//     }
//     return ans;
// }
helper help(treeNode<int> *root)
{
    if (root == NULL)
    {
        helper r(NULL, NULL);
        return r;
    }
    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        helper child = help(root->children[i]);
        if (child.m->data > ans.m->data)
        {
            if (child.sm == NULL)
            {
                ans.sm = ans.m;
                ans.m = child.m;
            }
            else
            {
                if (child.sm->data > ans.m->data)
                {
                    ans.sm = child.sm;
                    ans.m = child.m;
                }
                else
                {
                    ans.sm = ans.m;
                    ans.m = child.m;
                }
            }
        }
        else
        {
            if (ans.m->data != child.m->data && (ans.sm == NULL || child.m->data > ans.sm->data))
            {
                ans.sm = child.m;
            }
        }
    }
    return ans;
}

treeNode<int> *secondLargest(treeNode<int> *root)
{

    if (root == NULL)
        return NULL;
    helper ans = help(root);
    return ans.sm;
}

// 1 3 2 3 4 2 5 6 1 7 0 0 0 0

int main()
{
    treeNode<int> *root = takeInputLevel();
    print(root);
    cout << endl;
    // cout << count(root);
    // treeNode<int> *ans = nextLarger(root, 6);
    // cout << ans->data;
    treeNode<int> *ans = secondLargest(root);
    cout << ans->data;
}