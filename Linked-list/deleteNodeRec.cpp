#include <bits/stdc++.h>
#include "node.h"
using namespace std;

node *deleteRec(node *head, int i)
{
    if (head == NULL || i < 0)
    {
        return head;
    }
    if (i == 0)
    {
        node *a = head;
        head = a->next;
        delete a;
        return head;
    }

    head->next = deleteRec(head->next, i - 1);
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
    node *newHead = deleteRec(head, 0);
    print(newHead);
}