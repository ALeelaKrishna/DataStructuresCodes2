#include<stdio.h>

int graph[10][10],reach[10],n;

void depth(int v)
{
	int i;
 	reach[v]=1;
 	for(i=0;i<n;i++)
 	{
 
  if(graph[v][i] && !reach[i])
  {
   printf(" %d->%d ",v+1,i+1);
   depth(i);
  }}
}

void main()
{
	int num,i,j;
	printf("\n Vertices are 1,2,3...,n");
	printf("\n Enter the number of vertices (n): ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		printf("\nEnter adjecent elements of %d (enter -1 to stop) : ",i);
		num=2;
		while(num!=-1)
		{
			scanf("%d",&num);
			if(num<=n && num>=0)
				{
				 graph[i-1][num-1]=1;
				 graph[num-1][i-1]=1;
				}
				
				
				
			else if(num!=-1)
				printf("Entered vertix does not exist!!");
		}
	
	}
	
depth(0);
}
