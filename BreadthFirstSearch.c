#include<stdio.h>

int graph[10][10],q[10],reach[10],n,front=-1,rear=-1;

void breadth(int v)
{
  int j;
  
	printf(" %d->%d ", v,j );
	reach[v-1]=1;
	
			for(j=0;j<n;j++)
				if(graph[v-1][j]==1 && reach[j]!=1)
				{
					reach[j]=1;
					q[++rear]=j+1;
				}
		if(front<rear)		
		breadth(q[++front]);
	
	
}

void main()
{
	int num,i,j;
	for(i=0;i<10;i++)
		reach[i]=0;
		
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
	
	/*for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			if(graph[i][j]==1)
				printf(" 1 ");
			else printf(" 0 ");
			
			printf("\n");
	
	}*/
	
breadth(1);
}