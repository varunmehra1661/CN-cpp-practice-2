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

node *append(node *head, int N)
{
    int len = length(head);
    node *tail = head;
    int pTail = 1;
    while (pTail <= (len - N) - 1)
    {
        tail = tail->next;
        pTail++;
    }
    node *newHead = tail->next;
    tail->next = NULL;
    node *a = newHead;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = head;
    return newHead;
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
    node *newHead = append(head, 3);
    print(newHead);
}