#include<stdio.h>
#include<stdlib.h>

int a[100];

void Insert(int value)
{
 int hash=value%7;
 if(a[hash]==-1)
 {
 	a[hash]=value;
 }
 else
 {
    while(a[hash]!=-1)
    {
    	hash=(hash+1)%100;
    }
    a[hash]=value;
 }
}

void Delete(int del)
{   int i;
	for(i=0;i<100;i=i+1)
	{
		if(del==a[i])
		{
			a[i]=-1;
			break;
		}

	}
	if(i==101)
		printf("No such element to delete\n");
}

void Display()
{
  int i;
   for(i=0;i<100;i=i+1)
   {
   	 if(a[i]==-1)
   	 {
   	 	printf("%d:~~\n",i);
   	 }

   	 else
   	 {
   	 	printf("%d:%d\n",i,a[i]);
   	 }
   }
}

int main(void)
{
   int n,i;
     
     for(i=0;i<100;i=i+1)
     {
     	a[i]=-1;
     }
     while(1)
     {
       printf("Enter the option you want to perform");
       printf("\n1.Insertion\n2.Display\n3.Deletion\n4.Exit\n");
       int option;	
       scanf("%d",&option);
       switch(option)
       {
       	case 1:
       	       for(i=0;i<70;i=i+1)
               { 
               int value;
       	       value=rand()%100;
               Insert(value);
               }break;
        case 2:
               Display();
               printf("\n");
               break;
         
        case 3:printf("Enter the value you want to delete\n");
               int del;
               scanf("%d",&del);
               Delete(del);
               break;

        case 4:
               exit(0);
               printf("\n");
               break;
       }
     }

	return(0);
}