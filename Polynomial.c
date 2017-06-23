#include<stdio.h>
#include<stdlib.h>

struct node{
	int coefficient;
	int power;
	struct node *next_ptr;
};

struct node *current=NULL;
struct node *previous=NULL;
struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;

struct node *Create(struct node *start)
{   char k;
	while(1)
	{
		printf("Do You Want to Contiue(Y/N)\n");
		scanf("%s",&k);
		if(k=='y'||k=='Y')
         {
          printf("Enter the Coefficient and Power of the \nterm which you are about to enter\n");
          int m,n;
          scanf("%d %d",&m,&n);
          struct node *new_node=malloc(sizeof(struct node));

          new_node->coefficient=m;
          new_node->power=n;
          new_node->next_ptr=NULL;

          if(start==NULL)
           	start=new_node;

          else
          {
          	current=start;

          	if(new_node->power>start->power)
          	 {
          	 	start=new_node;
          	    start->next_ptr=current;
          	    
             }

             else
             { 

             	while(current!=NULL && new_node->power<current->power)
             	{
             	  previous=current;
                  current=current->next_ptr;
             	}

             	if(current==NULL)
             		previous->next_ptr=new_node;

             	else
             	{
             		previous->next_ptr=new_node;
             		new_node->next_ptr=current;
             	}

              }
          }
         
         }

        else
        	break;

	}
	return(start);
}

void AddPoly(struct node *start1,struct node *start2,struct node *start3)
    {
    while(start1->next_ptr && start2->next_ptr)
    {
    if(start1->power>start2->power)
    {
    start3->power=start1->power;
    start3->coefficient=start1->coefficient;
    start1=start1->next_ptr;
    }
    else if(start1->power<start2->power)
    {
    start3->power=start2->power;
    start3->coefficient=start2->coefficient;
    start2=start2->next_ptr;
    }
    else
    {
    start3->power=start1->power;
    start3->coefficient=start1->coefficient+start2->coefficient;
    start1=start1->next_ptr;
    start2=start2->next_ptr;
    }
    start3->next_ptr=(struct node *)malloc(sizeof(struct node));
    start3=start3->next_ptr;
    start3->next_ptr=NULL;
    }
    while(start1->next_ptr || start2->next_ptr)
    {
    if(start1->next_ptr)
    {
    start3->power=start1->power;
    start3->coefficient=start1->coefficient;
    start1=start1->next_ptr;
    }
    if(start2->next_ptr)
    {
    start3->power=start2->power;
    start3->coefficient=start2->coefficient;
    start2=start2->next_ptr;
    }
    start3->next_ptr=(struct node *)malloc(sizeof(struct node));
    start3=start3->next_ptr;
    start3->next_ptr=NULL;
    }
    }

void Display(struct node *start)
{
    current=start;
    while(current->next_ptr!=NULL)
	{
      printf("%dx^(%d)+",current->coefficient,current->power);
      current=current->next_ptr;
	}
	printf("%dx^(%d)\n",current->coefficient,current->power);
}

int main(void)
{
  while(1)
  { 
  	printf("Enter the option\n");
    printf("1.Create start1\n2.Create start2\n3.Add Polys\n4.Exit\n");
    int option;
    scanf("%d",&option);

  	switch(option)
  	{
  		case 1:start1=Create(start1);
  		       Display(start1);
  		       break;

  		case 2:start2=Create(start2);
  		       Display(start2);
  		       break;

  		case 3:AddPoly(start1,start2,start3);
  		       Display(start3);
  		       break;

  		case 4:exit(0);
  		       break;
  	}
  }

	return(0);
}
