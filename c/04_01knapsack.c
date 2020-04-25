/*
  Implementation of 0/1 knapsack problem using dynamic programming
*/

#include <stdio.h>

#define MAX 10
#define MAXIMUM(a,b)(a>b?a:b)

void knapsack(int no, int wt, int pt[MAX], int weight[MAX])
{
    int knap[MAX][MAX]={0} ,x[MAX]={0},i,j;
    for (i = 1; i <= no; i++)
      for (j = 1; j <= wt; j++)
      {
        if ((j-weight[i])<0)
          knap[i][j]=knap[i-1][j];
        else
          knap[i][j]=MAXIMUM(knap[i-1][j],pt[i]+knap[i-1][j-weight[i]]);
      }
    printf("Max profit : %d\n", knap[no][wt]);
    printf("Edges are : \n");
    for (i = no; i >= 1; i--)
      if (knap[i][wt] != knap[i-1][wt])
      {
        x[i] = 1;
        wt -= weight[i];
      }
    for (i = 1; i <= no; i++)
      printf("%d\t",x[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
  int no,wt,pt[MAX]={0},weight[MAX]={0},i;
  printf("Enter the Number of objects : \n :");
  scanf("%d",&no);
  printf("Enter the total Weigth :\n :");
  scanf("%d",&wt);
  printf("Enter the Weigths: \n");
  for (i = 1; i <= no; i++)
    scanf("%d",&weight[i]);
  printf("Enter the Profit: \n");
  for (i = 1; i <= no; i++)
    scanf("%d",&pt[i]);

  knapsack(no,wt,pt,weight);
  return 0;
}

/*Output
Enter the Number of objects :
 :4
Enter the total Weigth :
 :5
Enter the Weigths:
2 1 3 2
Enter the Profit:
12 10 20 15
Max profit : 37
Edges are :
1	1	0	1
*/
