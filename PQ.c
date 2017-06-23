#include<stdio.h>
#include<stdlib.h>


struct node 
{
 int priority;
 struct node *right_ptr;
 struct node *left_ptr;
 char RollNo; 
};

struct node *start=NULL;
struct node *end=NULL;
struct node *current;
struct node *temp;

//INSERTION AT BEGINING

void Enqueue(char a)
{
	struct node *new_node=malloc(sizeof(struct node));
	new_node->right_ptr=NULL;
	new_node->left_ptr=NULL;
	new_node->RollNo=a;

	if(start==end && start==NULL)
	{
      start=new_node;
      end=new_node;
	}

	else
	{
		new_node->left_ptr=start;
		start->right_ptr=new_node;
		start=new_node;
	}
}

//DELETION AT END

void Dequeue()
{

 if(start==end && start==NULL)
 {
 	printf("No element to Dequeue\n");
 }	

 else if(start==end && start!=NULL)
 {
 	start=NULL;
 	end=NULL;
 	printf("Queue has been emptied\n");
 }

 else
 {
  temp=end;
  end=end->right_ptr;
  end->left_ptr=NULL;
  temp->right_ptr=NULL;
  free(temp);
 }

}

void DisplayLR(struct node *end)
{
	if(end==NULL)
	{
		printf("No element is present in the Queue\n");

	}

	else if(start==end)
	{
		printf("%c",start->RollNo);
	}

	else
	{
        while(end!=start)
        {
        	printf("%c<-->",end->RollNo);
            end=end->right_ptr;
        }

        printf("%c\n",end->RollNo);
	}
}

void DisplayRL(struct node *start)
{
	if(start==NULL)
	{
		printf("No element is present in the Queue\n");

	}

	else if(start==end)
	{
		printf("%c",start->RollNo);
	}

	else
	{
        while(start!=end)
        {
        	printf("%c<-->",start->RollNo);
            start=start->left_ptr;
        }

        printf("%c\n",start->RollNo);
	}
}

int main(void)
{
	while(1)
  {

    printf("Enter the option you want to perform\n");
    printf("1.Enqueue\n2.Dequeue\n3.DisplayLR\n4.DisplayRL\n5.Exit\n");
    int option;
    scanf("%d",&option);
    switch(option)
    { 
    	case 1:printf("Enter the RollNo\n");
    	       char r;
    	       scanf("%s",&r);
    	       Enqueue(r);
    	       break;
         
        case 2:Dequeue();
               break;

        case 3:DisplayLR(end);
               break;   

        case 4:DisplayRL(start);
               break;

        case 5:exit(0);
               break;   

    }
  }
	return(0);
}