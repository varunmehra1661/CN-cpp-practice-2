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

node *midOfLL(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head, *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node *merge2sorted(node *h1, node *h2)
{
    node *fH = NULL;
    node *fT = NULL;
    if (h1->data < h2->data)
    {
        fH = h1;
        fT = h1;
        h1 = h1->next;
    }
    if (h1->data > h2->data)
    {
        fH = h2;
        fT = h2;
        h2 = h2->next;
    }
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data < h2->data)
        {
            fT->next = h1;
            fT = h1;
            h1 = h1->next;
        }
        else if (h1->data > h2->data)
        {
            fT->next = h2;
            fT = h2;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
    {
        fT->next = h2;
    }
    if (h2 == NULL)
    {
        fT->next = h1;
    }
    return fH;
}

node *mergeSort(node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    node *fH = head;
    node *mid = midOfLL(head);
    node *sH = mid->next;
    mid->next = NULL;

    node *fHalf = mergeSort(fH);
    node *sHalf = mergeSort(sH);

    node *finalHead = merge2sorted(fHalf, sHalf);
    return finalHead;
}

int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    node *fH = mergeSort(head);
    cout << endl;
    print(fH);
}