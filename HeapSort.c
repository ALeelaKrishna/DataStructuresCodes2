#include<stdio.h>
#include<stdlib.h>

int a[10];
int n=0;
void display()
{
	int i;
	for(i=1;i<11;i++)
	{
			printf("%d -- ",a[i]);
	}
			printf("\n");
}
void insert(int value)
{
	int temp;
	if(n>=10)
		printf("heap is full");
	else
	{
		n++;
		a[n]=value;
		int i=n;
		int p;
		p=i/2;
		while (p>=1 && a[p]<a[i])
		{
			temp=a[i];
			a[i]=a[p];
			a[p]=temp;
			i=p;
			p=p/2;
			
		}
		
	}
	display();
}
void delete()
{
	if(n==1)
	{
		
		printf("\nHeap is empty\n");
	}
	else
	{
	
		int item=a[1];
		int temp;
		printf("\n%d\n",item);
		a[1]=a[n];
		
		n--;
		int i=1;
		int lc=2*i;
		int rc=lc+1;
		while(i<=4)
		{
			if(a[i]<a[lc] && a[i]<a[rc])
			{
				if(a[rc]<a[lc])
				{
					temp=a[i];
					a[i]=a[lc];
					a[lc]=temp;
					i=lc;
					lc=2*i;
					rc=lc+1;
				}
				else if(a[lc]<a[rc])
				{
					temp=a[i];
					a[i]=a[rc];
					a[rc]=temp;
					i=rc;
					lc=2*i;
					rc=lc+1;
				}
			}
			else if(a[i]<a[lc] && a[i]>a[rc])
			{
					temp=a[i];
					a[i]=a[lc];
					a[lc]=temp;
					i=lc;
					lc=2*i;
					rc=lc+1;
			}
			else if(a[i]>a[lc] && a[i]<a[rc])
			{
					temp=a[i];
					a[i]=a[rc];
					a[rc]=temp;
					i=rc;
					lc=2*i;
					rc=lc+1;
			}
			else
				break; 
		}
		a[n+1]=item;
		
	}
	display();
}


void main()
{
	int i;
	
	int opt,value;
	while(1)
	{
		printf("1.insert\t2.delete\t3.display\t4.exit");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&value);
				insert(value);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
		}
	}
}
