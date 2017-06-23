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

void Enqueue(int p,char a)
{
	struct node *new_node=malloc(sizeof(struct node));
	new_node->right_ptr=NULL;
	new_node->left_ptr=NULL;
	new_node->RollNo=a;
  new_node->priority=p;

	if(start==end && start==NULL)
	{
      start=new_node;
      end=new_node;
	}

	else
	{   current=start;
		while(current->priority<new_node->priority)
		{
			current=current->left_ptr;
		}
		new_node->right_ptr=current->right_ptr;
		current->right_ptr->left_ptr=new_node;
		current->right_ptr=new_node;
		new_node->left_ptr=current;
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
		printf("%c-(%d)",start->RollNo,end->priority);
	}

	else
	{
        while(end!=start)
        {
        	printf("%c-(%d)<-->",end->RollNo,end->priority);
            end=end->right_ptr;
        }

        printf("%c-(%d)\n",end->RollNo,end->priority);
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
		printf("%c-(%d)",start->RollNo,start->priority);
	}

	else
	{
        while(start!=end)
        {
        	printf("%c-(%d)<-->",start->RollNo,start->priority);
            start=start->left_ptr;
        }

        printf("%c-(%d)\n",start->RollNo,start->priority);
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
    	       int p;
    	       scanf("%s",&r);
    	       printf("Enter priority\n");
    	       scanf("%d",&p);
    	       Enqueue(p,r);
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