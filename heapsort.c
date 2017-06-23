#include<stdio.h>
#include<stdlib.h>

int a[10];
int n=0;
void display()
{
	int i;
	for(i=0;i<11;i++)
		if(a[i]!=-1)
			printf("%d -- ",a[i]);
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
		int i;
		for(i=-1;i<=10;i++)
			a[i]=-1;
		printf("Heap is empty");
	}
	else
	{
	
		int item=a[1];
		int temp;
		a[1]=a[n];
		a[n]=-1;
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
	}
	display();
}


void main()
{
	int i;
	for(i=-1;i<=10;i++)
		a[i]=-1;
	insert(33);
	insert(14);
	insert(65);
	insert(2);
	insert(76);
	insert(69);
	insert(59);
	insert(85);
	insert(47);
	insert(99);
	insert(98);
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
