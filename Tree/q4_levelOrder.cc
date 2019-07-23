#include <bits/stdc++.h>
using namespace std;
void levelOrder(struct Node* node);
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void levelOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *node = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (node == NULL)
             node = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     levelOrder(node);
     cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
//You are required to complete this method
void levelOrder(Node* node)
{
  //first make a list and initialize it with atleast the head
  //then going to print only the immediate left and right of the head
  //and push the next set of child
  //if my list is empty means end of function
  
  if(!node) return;
  //means root exists
  queue <Node*> q;
  q.push(node);
  Node* marker = NULL;
  q.push(marker);
  Node* cur;
      
  //queue is all set
  while(q.empty() == false ){
      //as long as my queue is not empty
      cur = q.front();
      q.pop();
      if(cur == NULL){
        //cur is a marker
        cout << endl;
      }
      else{
        cout << cur->data << " ";
        if(cur->left != NULL){
          q.push(cur->left);
        }
        if(cur->right != NULL){
          q.push(cur->right);
          q.push(marker);
        }
      }
  }
}