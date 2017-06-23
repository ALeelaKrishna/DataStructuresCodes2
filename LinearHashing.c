#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next_ptr;
}; 

struct node *current=NULL;
struct node *a[703];

void Insert(int value)
{
	struct node *new_node=malloc(sizeof(struct node));
	new_node->data=value;
	new_node->next_ptr=NULL;
	int hash=value%703;
   if(a[hash]==NULL)
   {
   	a[hash]=new_node;
   }
   else
   {
   	current=a[hash];
   	while(current->next_ptr!=NULL)
   	{
   		current=current->next_ptr;
   	}
   	current->next_ptr=new_node;
   }

}

void Display()
{
  int i;
   for(i=0;i<703;i=i+1)
   {
   	 if(a[i]==NULL)
   	 {
   	 	printf("%d:~~\n",i);
   	 }

   	 else
   	 {
   	 	current=a[i];
   	 	printf("%d:",i);
   	 	while(current!=NULL)
   	 	{   
   	 		printf("%d->",current->data);
            current=current->next_ptr;  	 	
   	 	}
        printf("\n");
      
   	 }
   }
}

int main(void)
{
   int n,i;
     
     while(1)
     {
       printf("Enter the option you want to perform");
       printf("\n1.Insertion\n2.Display\n3.Exit\n");
       int option;	
       scanf("%d",&option);
       switch(option)
       {
       	case 1:
               for(i=0;i<2000;i=i+1)
               { 
               int value;
       	       value=rand();
               Insert(value);
               }break;
        case 2:
               Display();
               printf("\n");
               break;

        case 3:
               exit(0);
               printf("\n");
               break;
       }
     }

	return(0);
}