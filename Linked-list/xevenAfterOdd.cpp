#include <bits/stdc++.h>
using namespace std;
#include "node.h"

void print(node *n1)
{
    node *head = n1;
    node *temp = n1;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *takeInputLL()
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
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

node *eveOdd(node *head)
{
    node *oddH = NULL;
    node *oddT = NULL;
    node *evenH = NULL;
    node *evenT = NULL;

    if (!head || !head->next)
    {
        return head;
    }

    while (head != NULL)
    {
        if (head->data % 2 != 0)
        {
            if (oddH == NULL)
            {
                oddH = head;
                oddT = head;
            }
            oddT->next = head;
            oddT = head;
            head = head->next;
        }
        if (head->data % 2 == 0)
        {
            if (evenH == NULL)
            {
                evenH = head;
                evenT = head;
            }
            evenT->next = head;
            evenT = head;
            head = head->next;
        }
    }
    oddT->next = NULL;
    evenT->next = NULL;

    if (evenH == NULL)
    {
        return oddH;
    }
    if (oddH == NULL)
    {
        return evenH;
    }

    evenT->next = oddH;
    return evenH;
}

int main()
{
    node *head = takeInputLL();
    print(head);
    // cout << endl;
    node *fH = eveOdd(head);
    cout << endl;
    print(fH);
}