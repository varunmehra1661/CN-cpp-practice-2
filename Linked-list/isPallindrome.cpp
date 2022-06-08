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
    cout << slow->data;
}

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

bool isPallindrome(node *head)
{
    node *mid = midOfLL(head);
    node *fH = head;
    node *t2 = mid->next;
    mid->next = NULL;
    node *sH = reverseLL(t2);

    while (!fH || !sH)
    {
        if (fH != sH)
        {
            return false;
        }
        fH = fH->next;
        sH = sH->next;
    }

    return true;
}

int main()
{
    node *head = takeInputLL();
    print(head);
    cout << endl;
    cout << isPallindrome(head);
}