#include<stdio.h>
#include<stdlib.h>
int a[8];
struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root=NULL;
struct node *current=NULL;

//INSERT

void Insert(int x)
{
 struct node *new_node=malloc(sizeof(struct node));
 new_node->data=x;
 new_node->right=NULL;
 new_node->left=NULL;
  if(root==NULL)
    root=new_node;
  else
   {
    current=root;
    while(1)
    {
     if(current->data<new_node->data)
      {
       if(current->right==NULL)
       {
        current->right=new_node;
        break;
       }
       current=current->right;
      } 
     else if(current->data>new_node->data)
       {
       if(current->left==NULL)
        {
        current->left=new_node;
        break;
        }
       current=current->left;
       }
     else if(current->data==new_node->data)
      {
      printf("Enter a valid data \n");
      break;
      }
     }
   }
  }

//INORDER DISPLAY

void InOrderDisplay(struct node *root)
{ 
	int i=0;
  if(root!=NULL)
  {
   InOrderDisplay(root->left);
   a[i++]=root->data;
     printf("%d\t",root->data);
     
   InOrderDisplay(root->right);
  }

 }

//SEARCH

struct node *Search(struct node *root,int key)
{
  current=root;
  if(current==NULL)
  {
   printf("ERROR 404\n Match not found\n"); 
   return(0);
  }
 while(1)
 {
  if(current->data==key)
   {
   return(current);
   break;
   }
   else if(current->right==NULL && current->left==NULL)
  {
   printf("ERROR 404 Match not found\n"); 
   break;
  }
  else if(current->data>key)
   current=current->left;
  else if(current->data<key)
   current=current->right;  
   }  
}

//MAIN FUNCTION

int main(void)
{
   int k1;
   int k2;
while(1)
 {
  printf("Enter the option you want to perform\n");
  printf("1.Insertion\n2.Display(IO)\n");
  int option;
  scanf("%d",&option);
  switch(option)
  {
   case 1:printf("Enter the number you want to insert\n");
          int x;
          scanf("%d",&x);
          Insert(x);
          break;

   case 2:

          InOrderDisplay(root);
          printf("\n");
           int i;
            for(i=0;i<8;i=i+1)
  {
  	printf("%d ",a[i]);
  }
          break;

     
    }
  }     
 
return(0);        
}
