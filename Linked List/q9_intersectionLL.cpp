#include<iostream>
#include<stdio.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
int intersectPoint(struct Node* head1, struct Node* head2);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }
        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
/*This is a function problem.You only need to complete the function given below*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */

int findNumberOfNode(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp){
        temp = temp->next;
        n++;
    }
    delete temp;
    return n;
}


int intersectPoint(Node* head1, Node* head2)
{
    Node* one = head1;
    Node* second = head2;
    int l1 = findNumberOfNode(head1);
    int l2 = findNumberOfNode(head2);
    if(l1<l2){

       for (int i = 0; i < l1 ; ++i){
            for (int j = 0; j < l2; ++j){
                if(one->next == second->next){
                    return one->next->data;
                }
                second = second->next;
            }
        one = one->next;
        second = head2;
       }
       return -1;
    }
    else{
        for (int i = 0; i < l2 ; ++i){
            for (int j = 0; j < l1; ++j){
                if(second->next == one->next){
                    return second->next->data;
                }
                one = one->next;
            }
        second = second->next;
        one = head1;
        }
        return -1;
    }  
}
