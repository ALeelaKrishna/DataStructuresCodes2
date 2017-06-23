#include<stdio.h>
#includ<stdlib.h>

int main(void)
{ 
  int v,i,j;
  printf("Enter the number of vertices you want to insert\n");
  scanf("%d",&v);
  int a[v][v];

//  INITIALISING THE ADJACENCY MATRIX AND ENTERING 0 IN THE DIAGONAL ELEMENTS

  for(i=1;i<=v;i=i+1)
  {
    for(j=1;j<=v;j=j+1)
    {
        if(i==j)
        {
         a[i][j]=0;
        }
        else
         {
            a[i][j]=-1;
         }   
    }
  }

// ENTERING THE RELATIONS

for(i=1;i<=v;i=i+1)
{
    for(j=0;j<=v;j=j+1)
    {
        
    }
} 


 


  return(0);  
}