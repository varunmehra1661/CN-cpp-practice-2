#include <bits/stdc++.h>
#include "C:\Users\Varun Mehra\OneDrive\Desktop\prog files\April prac c++\Binary Trees\classBT.h"
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
class Pair
{
public:
    Node<int> *head;
    Node<int> *tail;
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

Pair construct(binaryTree<int> *root)
{
    if (!root)
    {
        Pair ans;
        ans.head = NULL;
        ans.tail = NULL;
        return ans;
    }

    Node<int> *node = new Node<int>(root->data);

    Pair leftAns = construct(root->left);
    Pair rightAns = construct(root->right);
    Pair ans;

    if (leftAns.head == NULL and rightAns.head == NULL)
    {
        ans.head = node;
        ans.tail = node;
    }
    else if (!leftAns.head && rightAns.head)
    {
        ans.head = node;
        node->next = rightAns.head;
        ans.tail = rightAns.tail;
    }
    else if (leftAns.head && !rightAns.head)
    {
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        ans.tail = node;
    }
    else
    {
        ans.head = leftAns.head;
        leftAns.tail->next = node;
        node->next = rightAns.head;
        ans.tail = rightAns.tail;
    }
    return ans;
}

Node<int> *constructLL(binaryTree<int> *root)
{
    return construct(root).head;
}
void print(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(input) / sizeof(int);
    binaryTree<int> *root = constructTree(input, n);
    printLevel(root);
    Node<int> *head = constructLL(root);
    print(head);
}
