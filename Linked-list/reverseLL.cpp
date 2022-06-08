#include <bits/stdc++.h>
#include "node.h"
using namespace std;

node *reverseLL(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *after;
    while (curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    head = prev;
    return head;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *takeInput()
{
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newNode = new node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int main()
{
    node *head = takeInput();
    print(head);
    cout << endl;
    node *nH = reverseLL(head);
    print(nH);
}