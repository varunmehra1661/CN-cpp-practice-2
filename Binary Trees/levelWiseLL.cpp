#include <bits/stdc++.h>
#include "classBT.h"
using namespace std;
template <typename T>
class node
{
public:
    T data;
    node *next;
    node(T data)
    {
        this->data = data;
        next = NULL;
    }
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

vector<node<int> *> createLLForEachLevel(binaryTree<int> *root)
{
    vector<node<int> *> v;
    if (!root)
    {
        v.push_back(NULL);
        return v;
    }

    queue<binaryTree<int> *> pendingQ;
    pendingQ.push(root);
    pendingQ.push(NULL);

    node<int> *head = NULL;
    node<int> *tail = NULL;

    while (pendingQ.empty())
    {
        binaryTree<int> *curr = pendingQ.front();
        pendingQ.pop();

        if (curr == NULL)
        {
            tail->next = NULL;

            if (pendingQ.size() == 0)
                break;

            pendingQ.push(NULL);

            head = NULL;
            tail = NULL;
        }
        else
        {
            node<int> *n = new node<int>(curr->data);
            if (head == NULL)
            {
                head = tail = n;
                v.push_back(head);
            }
            else
            {
                tail->next = n;
                tail = n;
            }

            if (curr->left)
                pendingQ.push(curr->left);
            if (curr->right)
                pendingQ.push(curr->right);
        }
    }
}

// 1 2 3 4 5 6 7 -1 -1 -1 10 -1 -1 12 11 -1 -1 -1 -1 -1 -1

int main()
{
    binaryTree<int> *root = takeInput();
    // printLevel(root);
    cout << endl;
    vector<node<int> *> ans = createLLForEachLevel(root);
}