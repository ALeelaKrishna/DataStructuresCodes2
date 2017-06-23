
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int x;
  struct node *left;
  struct node *right;
}*root=NULL,*temp;

struct node* new_node(int data)
{
  struct node *n=(struct node*)malloc(sizeof(struct node));
  n->x=data;
  n->left=NULL;
  n->right=NULL;
  return n;
}


int count(struct node *n)
{
    int c = 1;

    if (n == NULL)
        return 0;
    else
    {
        c=c + count(n->left);
        c=c + count(n->right);
        
        return c;
     }
}

int isfull(struct node *r)
{
  if(count(r->left)==count(r->right))
   return 1;
  else
   return 0;
}

void insert(struct node *r,struct node *t)
{
  if(r->left==NULL)
    r->left=t;
  else if(r->right==NULL)
    r->right=t;
  else
  {
    if(isfull(r))
      insert(r->left,t);
    else if(!isfull(r->left))
      insert(r->left,t);
    else 
      insert(r->right,t);
  }
}

void inorder(struct node *r)
{
  if(r==NULL)
    return;
  else
  {
    inorder(r->left);
    printf("  %d",r->x);
    inorder(r->right);
  }
}

void preorder(struct node *r)
{
  if(r==NULL)
    return;
  else
  {
    printf("  %d",r->x);
    preorder(r->left);
    preorder(r->right);
  }
}

void postorder(struct node *r)
{
  if(r==NULL)
    return;
  else
  {
    postorder(r->left);
    postorder(r->right);
    printf("  %d",r->x);
  }
}

void main(void)
{
  int ch;
  char y;
  int data;
  struct node *temp;
  
  while(1)
  {
    printf("\n1:Insert\n2:Inorder Traversal\n3:Preorder Traversal\n4:Postorder Traversal\n5:Exit\nEnter you choice: \n");
    scanf("%d",&ch);
    

    switch(ch)
    {
      case 1:
          printf("\nEnter data value: ");
          scanf("%d",&data);
          temp=new_node(data);
          if(root==NULL)
          {
            root=temp;
          }
          else
          insert(root,temp);

        break;

      case 2:
        inorder(root);
        break;

      case 3:
        preorder(root);
        break;

      case 4:
        postorder(root);
        break;

      case 5:
        exit(0);
      
    }
  }
}
