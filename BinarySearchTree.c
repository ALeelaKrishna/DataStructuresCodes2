#include<stdio.h>
#include<stdlib.h>

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
  if(root!=NULL)
  {
   InOrderDisplay(root->left);
   printf("%d\t",root->data);
   InOrderDisplay(root->right);
  }
 }

//PREORDER DISPLAY

void PreOrderDisplay(struct node *root)
{
  if(root!=NULL)
  {
   printf("%d\t",root->data);
   PreOrderDisplay(root->left);
   PreOrderDisplay(root->right);
  }
 }

//POSTORDER DISPLAY

void PostOrderDisplay(struct node *root)
{
  if(root!=NULL)
  {
   PostOrderDisplay(root->left);
   PostOrderDisplay(root->right);
   printf("%d\t",root->data);
  }
 }   

//MAXIMUM

struct node *Maximum(struct node *root)
 {
  current=root; 
  while(current->right!=NULL)
   {
    current=current->right;
   }
  return(current);
 }

//MINIMUM

struct node *Minimum(struct node *root)
 {
  current=root; 
  while(current->left!=NULL)
   {
    current=current->left;
   }
  return(current);
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

//SUCCESSOR

struct node *Successor(struct node *root,int l)
{
 current=Search(root,l);
 if(current->right!=NULL)
  {
   return(Minimum(current->right));
  }
 else
  {
    struct node *succ=NULL;
    struct node *previous=root;
    while(previous!=current)
     {
      if(current->data<previous->data)
       {
        succ=previous;
        previous=previous->left;
       }
      else
         previous=previous->right;
     }
   return(succ);
   
  }
}

//PREDECESSOR

struct node *Predecessor(struct node *root,int l)
{
 current=Search(root,l);
 if(current->left!=NULL)
  {
   return(Maximum(current->left));
  }
 else
  {
    struct node *pred=NULL;
    struct node *previous=root;
    while(previous!=current)
     {
      if(current->data>previous->data)
       {
        pred=previous;
        previous=previous->right;
       }
      else
         previous=previous->left;
     }
   return(pred);
   
  }
}

// PARENT OF A NODE
 
struct node *Parent(struct node *root,int x)
{
 struct node *current=Search(root,x);
 struct node *temp=root;
 struct node *parent=NULL;
 while(temp!=current)
  {
   if(temp->data>current->data)
    {
     parent=temp;
     temp=temp->left;
    }
   else
    {
     parent=temp;
     temp=temp->right;
  }
 
 }
return(parent);
} 

//DELETION

void Delete(struct node *root,int del)
{
  struct node *current=Search(root,del);
  struct node *parent=Parent(root,del);
  
  //CASE 1:

  if(current->right==NULL && current->left==NULL)
   {
    if(parent->right==current)
     parent->right=NULL;
    else
     parent->left=NULL;
   
   }

   //CASE 2:

   else if(current->left==NULL)
   {
    if(parent->left==current)
    {
      parent->left=current->right;
      current=NULL;
      free(current);
    }
    else
    {
      parent->right=current->right;
      current=NULL;
      free(current);
    }
   
   }

   else if(current->right==NULL)
   {
    if(parent->left==current)
    {
      parent->left=current->left;
      current=NULL;
      free(current);
    }
    else
    {
      parent->right=current->left;
      current=NULL;
      free(current);
    }
    
   }
 
 //CASE 3:

  else
  {
  struct node *successor=Successor(current,del);
  struct node *temp=NULL;
    
    if(parent->left==current)
    {
      temp=successor;
      Delete(root,successor->data);
      parent->left=temp;
    }

    else if(parent->right==current)
    {
      temp=successor;
      Delete(root,successor->data);
      parent->right=temp;
    }

  }


}

//HEIGHT OF A BINARY TREE

int height(struct node *root)
{
  int Lheight,Rheight;

  if(root==NULL)
    return 0;

  Lheight=height(root->left);
  Rheight=height(root->right);

  if(Lheight>Rheight)
    return Lheight+1;
  else
    return Rheight+1;
  
}

//NUMBER OF NODES

int count(struct node *n)
{
    int c = 1;

    if (n == NULL)
        return 0;
    else
    {
        c += count(n->left);
        c += count(n->right);
        
        return c;
     }
}

//MAIN FUNCTION

int main(void)
{
while(1)
 {
  printf("Enter the option you want to perform\n");
  printf("1.Insertion\n2.Display(IO)\n3.PostOrderDisplay\n4.PreOrderDisplay\n5.Maximum\n6.Minimum\n7.Successor\n8.Predecessor\n9.Exit\n10.Search\n11.Deletion\n12.Height\n13.Number of Nodes\n");
  int option;
  scanf("%d",&option);
  switch(option)
  {
   case 1:printf("Enter the number you want to insert\n");
          int x;
          scanf("%d",&x);
          Insert(x);
          break;
   case 2:InOrderDisplay(root);
          printf("\n");
          break;
   case 3:PostOrderDisplay(root);
          printf("\n");
          break;
   case 4:PreOrderDisplay(root);
          printf("\n");
          break;
   case 5:Maximum(root);
          printf("The maximum element present is %d",current->data);
          printf("\n");
          break;
   case 6:Minimum(root);
          printf("The minimum element present is %d",current->data);
          printf("\n");
          break;  
  case 7: printf("Enter the number for which you want to find the successor");
          int y;
          scanf("%d",&y);
          struct node *successor=NULL;
          successor=Successor(root,y);
          printf("The successor of %d is %d",y,successor->data);
          printf("\n");
          break;
  case 8:printf("Enter the number for which you want to find the predecessor");
          int z;
          scanf("%d",&z);
          struct node *predecessor=NULL;
          predecessor=Predecessor(root,z);
          printf("The predecessor of %d is %d",z,predecessor->data);
          printf("\n");
          break;
   case 9:exit(0);
          break;
   case 10:printf("Enter the key you want to search\n");
           int key;
           scanf("%d",&key);
           struct node *s=Search(root,key);
           if(s->data!=key)
           printf("NO Match found\n");
           else
           printf("Matched\n");
           break;
   case 11:printf("Enter the element you want to delete\n");
           int del;
           scanf("%d",&del);
           Delete(root,del);
           break;
   case 12:printf("The height of the given tree is %d\n",height(root));
           break;
   case 13:printf("the total number of nodes are %d\n",count(root));
           break;
     
    }
  }     
 
return(0);        
}
