#include<iostream>
using namespace std;
typedef struct TreeNode
{
int data;
struct TreeNode *left;
struct TreeNode *right;
}TreeNode;
typedef struct Node
{
struct TreeNode *TreeNode;
struct Node *next;
}Node;
class Queue
{
Node *front,*rear;
public:
Queue()
{
front=NULL;
rear=NULL;
}
int isEmpty()
{
return (front==NULL)?1:0;
}
void enque(TreeNode *t)
{
Node *p;
p=new Node();
p->TreeNode = t;
p->next=NULL;
if(front==NULL)
{
front=p;
rear=p;
}
else
{
rear->next = p;
rear = rear->next;
}
}
TreeNode* deque()
{
Node *p;
TreeNode *temp;
p = front;
temp = front->TreeNode;
if(front==rear)
{
front=NULL;
rear=NULL;
}
else
{
front = front->next;
}
delete p;
return temp;
}
};
class Tree {
TreeNode *t;
public:
Tree()
{
t=NULL;
}
TreeNode *insert(int x)
{
TreeNode *p,*q,*r;
p = new TreeNode();
p->data=x;
p->left=NULL;
p->right=NULL;
if(t==NULL)
return p;
q=t;
r=t;
while(r!=NULL)
{
q=r;
if(x < r->data)
r=r->left;
else
r=r->right;
}
if(x<q->data)
q->left=p;
else
q->right=p;
return t;
}
TreeNode *create()
{
int n,i,key;
cout<<"\nEnter the number of Nodes : ";
cin>>n;
for(i=0;i<n;i++)
{
cout<<"\nEnter the data : ";
cin>>key;
t=insert(key);
}
return t;
}
void inorder(TreeNode *t)
{
if(t!=NULL)
{
inorder(t->left);
cout<<"\t"<<t->data;
inorder(t->right);
}
}
TreeNode *del(TreeNode *t,int key)
{
TreeNode *temp;
if(t==NULL)
{
return NULL;
}
if(key<t->data)
{
t->left=del(t->left,key);
return t;
}
if(key>t->data)
{
t->right=del(t->right,key);
return t;
}
if(t->left==NULL&t->right==NULL)
{
temp=t;
delete temp;
return NULL;
}
if(t->left!=NULL && t->right==NULL)
{
temp=t;
t=t->left;
delete temp;
return t;
}
if(t->left==NULL && t->right!=NULL)
{
temp=t;
t=t->right;
delete temp;
return t;
}
temp = t->right;
t->data=temp->data;
t->right=del(t->right,temp->data);
return t;
}
};
int main() {
int choice,key;
TreeNode *root,*result;
Tree t;
do
{
cout<<"\nMENU";
cout<<"\n1.Create\n2.Insert\n3.Display\n4.Delete\n5.Exit";
cout<<"\n\nEnter your Choice : ";
cin>>choice;
switch(choice)
{
case 1:root = t.create();
break;
case 2:
cout<<"\nEnter the number to Insert : ";
cin>>key;
root=t.insert(key);
break;
case 3:
cout<<"\nBINARY TREE :-";
t.inorder(root);
break;
case 4:
cout<<"\nEnter the Node to delete :";
cin>>key;
result = t.del(root,key);
root=result;
cout<<"\nNODE DELETED";
break;
case 5:return 0;
default:cout<<"\nInvalid Choice !!";
}
}while(choice!=5);
}

