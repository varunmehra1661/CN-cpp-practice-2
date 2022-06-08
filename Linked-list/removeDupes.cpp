#include <bits/stdc++.h>
#include "node.h"
using namespace std;

int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

node *remDupes(node *head)
{

    node *t2 = head->next, *t1 = head;
    while (t2)
    {
        if (t2->data == t1->data)
        {
            // t1->next = t2->next;
            // node *t = t2;
            // t2 = t2->next;
            // delete t;

            node *t = t2;
            t2 = t2->next;
            t1->next = t2;
            delete t;
        }
        else
        {
            t1 = t1->next;
            t2 = t2->next;
        }
    }
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
    node *newhead = remDupes(head);
    print(newhead);
}