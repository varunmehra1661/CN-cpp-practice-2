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

node *skipMdeleteN(node *head, int M, int N)
{

    if (M == 0)
        return NULL; // edge case  not a base case

    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *temp = head;
    int count1 = 0;
    int count2 = 0;
    while (temp->next != NULL && count1 < M - 1) // travel M nodes
    {
        count1++;
        temp = temp->next;
    }
    node *t1 = temp;
    // t1=temp;
    temp = temp->next;
    if (temp == NULL)
        return head;

    while (temp->next != NULL && count2 < N - 1)
    {
        count2++;
        temp = temp->next;
    }

    node *t2;
    t2 = temp->next;

    node *m = skipMdeleteN(t2, M, N);
    t1->next = m;
    return head;
}

int main()
{
    node *head = takeInputLL();
    print(head);
    int N, M;
    cout << "Skip M delete N :::";
    cin >> M >> N;
    node *nH = skipMdeleteN(nH, M, N);
    print(nH);
}