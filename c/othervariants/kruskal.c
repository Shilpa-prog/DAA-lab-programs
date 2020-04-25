#include<stdio.h>
void kruskal(int n,int cost[10][10],int r[10]);
int find(int u,int r[10]);
void unionij(int i,int j,int r[],int n);



int main()
{
  int r[10],i,cost[10][10],j,n;
  printf("enter the no of vertices");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  r[i]=i;
  printf("enter the cost adjacency matrix");
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
     scanf("%d",&cost[i][j]);
   }
   kruskal(n,cost,r);
   return 0;
 }


void kruskal(int n,int cost[10][10],int r[10])
 {
   int count=0,select[10][2],k=0;
   int sum=0,min,i,j,u,v;
   while(count<n-1)
   {
     min=999;
     for(i=1;i<=n;i++)
     {
       for(j=1;j<=n;j++)
       {
         if(min>cost[i][j]&&cost[i][j]!=0)
         {
         min=cost[i][j];
         u=i;
         v=j;
         }
        }
      }
     i=find(u,r);
     j=find(v,r);
     if(i!=j)
     {
     select[k][0]=u;
     select[k][1]=v;
     count++;
     k++;
     sum=sum+cost[u][v];
     unionij(i,j,r,n);
     }
     cost[u][v]=cost[v][u]=999;
     }
     if(sum<999)
     {
        printf("spannig tree exist\n");
        printf("the sum of cost is%d\n",sum);
        printf("the edges are\n");
        for(i=0;i<n-1;i++)
        {

           printf("\t%d->%d\n",select[i][0],select[i][1]);
        }
      }
      else
      printf("spannig tree does not exist");
  }


int find(int u,int r[10])
{
  return r[u];
}

void unionij(int i,int j,int r[],int n)
{
  int k;
  if(i<j)
  {
      r[j]=i;
      for(k=1;k<=n;k++)
      {
        if(r[k]==j)
        {
        r[k]=i;
        }
      }
    }
      else
      {
        r[i]=j;
        for(k=1;k<=n;k++)
        {
        if(r[k]==i)
        r[k]=j;
        }
      }
}
