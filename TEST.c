#include<stdio.h>
#include<stdlib.h>
int v;
void Print(int a)
{ int i,j;
  for(i=1;i<=v;i=i+1)
  {
    for(j=1;j<=v;j=j+1)
    {
      printf("\t%d",a[i][j]);
    }
    printf("\n");
  }
}

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
Print(a);

  for(i=1;i<=v;i=i+1)
  {
    for(j=1;j<=v;j=j+1)
    {
      printf("\t%d",a[i][j]);
    }
    printf("\n");
  }



  return(0);  
}