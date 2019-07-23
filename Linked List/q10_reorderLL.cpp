#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
// A utility function to create a new node
Node* newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}
// Rearranges given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *rearrangeEvenOdd(Node *head);
/* Driver program to test above function*/
int main()
{
    int T,i,n,l;
    cin>>T;
    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;
            if (head == NULL)
                {   head = temp = newNode(l); }
            else
                {  temp->next = newNode(l);
                 temp = temp->next;
             }
         }
         head = rearrangeEvenOdd(head);
         while(head != NULL)
         {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Node structure
struct Node
{
    int data;
    struct Node* next;
}; */
Node *rearrangeEvenOdd(Node *head)
{
    Node *even,*odd,*evenstart;
    evenstart=head->next;
    odd=head;
    even=odd->next;
    while(even && even->next){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    return head;
}