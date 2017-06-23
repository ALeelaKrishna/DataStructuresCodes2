#include<stdio.h>
#include<stdlib.h>

int adj[11][11],visit[10],n;

void DFS(int i)

{

   int j;
	visit[i]=1;
	printf(" %d ",i);

	for(j=1;j<=n;j=j+1)
	{
		if(adj[i][j]!=0 && visit[j]==0)
			DFS(j);
	}
}

int main(void)
{
  int num=-1,i,j;

	printf("\nVertices are 1,2,3...,n");
	printf("\nEnter the number of vertices (n): ");
	scanf("%d",&n);
	
	//INITIALISING A MATRIX

	for(i=0;i<=n;i=i+1)
    	for(j=0;j<=n;j=j+1)
    	{
    		if(i==0)
    		 adj[i][j]=j;

    		else if(j==0)
    		 adj[i][j]=i;
    		
    		 else
    		 adj[i][j]=0;

    	}

    //ENTERING THE EDGES
 
	for(i=1;i<=n;i=i+1)
	{ 	
		printf("enter the number which you want to be adjacent to %d\n",i);
	    printf("\nif you want to stop enter -1\n\n");

		while(1)
	 {		
	    scanf("%d",&num);

        if(num==-1)
        	break;

	    adj[i][num]=1;

     }	

    }

   //PRINTING MATRIX

	for(i=0;i<=n;i=i+1)
	{
    	for(j=0;j<=n;j=j+1)
    	{
    		printf("  %d  ",adj[i][j]);
    	}
      
      printf("\n\n");
    
    }	
    
    for(i=1;i<=n;i++)
    	visit[i]=0;

 DFS(1);
printf("\n");

//CYCLIC OR ACYCLIC

int count =0;
int vertices;

    for(i=1;i<=n;i=i+1)
    	for(j=1;j<=n;j=j+1)
    		if(adj[i][j]==1)
    			count=count+1;
    count=count/2;
    vertices=n;
    if(count>=vertices)
    	printf("The given graph is CYCLIC\n");
    else
    	printf("The given graph is ACYCLIC\n");


	return(0);
}
 
 

 
