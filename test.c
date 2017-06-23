#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *start=NULL;
struct node *temp=NULL;


struct node *Create(int x)
{
  struct node *new_node=malloc(sizeof(struct node));
  new_node->data=x;
  new_node->left=NULL;
  new_node->right=NULL;
  return(new_node);
}

int count(struct node *start)
{
 int c=1;
  if(start==NULL)
    return 0;
  else
  {  
   c=c + count(start->left);
   c=c + count(start->right);
   return(c);
  }
}

int isfull(struct node *start)
{
 if(count(start->left)==count(start->right))
  return(1);
 else
  return(0); 
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


void InorderDisplay(struct node *start)
{
 if(start!=NULL)
   {
    InorderDisplay(start->left);
    printf(" %d ",start->data);
    InorderDisplay(start->right);  
   } 
}

int main(void)
{
int option;

while(1)
{
printf("\n1.Insert\n2.Display\n3.Exit\n");
printf("\nEnter the option\n");
scanf("%d",&option);
switch(option)
{
 case 1:
        
        printf("Enter the data\n");
        int x;
        scanf("%d",&x);
        temp=Create(x);
        if(start==NULL)
         start=temp;
        else
         insert(start,temp);
        break;
 
 case 2:InorderDisplay(start);
        break;
 
 case 3:exit(0);
        break;       
        
}
}
return(0);
}
