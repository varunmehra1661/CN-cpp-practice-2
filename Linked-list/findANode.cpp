#include <bits/stdc++.h>
#include "node.h"
using namespace std;

int find(node *head, int x, int count)
{
    node *temp = head;
    // int count = 0;

    // if (head == NULL)
    // {
    //     return;
    // }
    if (head->data == x)
    {
        return count;
    }
    if (head->data != x)
    {
        count++;
    }

    // while (temp != NULL)
    // {
    //     temp = temp->next;
    //     count++;
    //     if (temp->data == x)
    //     {
    //         return count;
    //     }
    // }

    find(head->next, x, count++);
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
    cout << find(head, 400, 0);
}