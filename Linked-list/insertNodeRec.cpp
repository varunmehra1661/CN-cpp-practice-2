#include <bits/stdc++.h>
#include "node.h"
using namespace std;

node *insertRecur(node *head, int i, int data)
{
    if (i == 0)
    {
        node *a = new node(data);
        a->next = head;
        head = a;
        return a;
    }
    if (head == NULL || i < 0)
    {
        return head;
    }
    head->next = insertRecur(head->next, i - 1, data);
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
    int newData;
    cout << "Enter the data to be inserted ::";
    cin >> newData;
    node *newHead = insertRecur(head, 3, newData);
    print(newHead);
}