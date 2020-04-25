#include<iostream>
#include<time.h>
#include<stdio.h>
using namespace std;

void dij(int src,int cost[][10],int dist[],int n)
{
	int visited[10],min,i,j,u;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		dist[i]=cost[src][i];
	}
	visited[src]=1;
	dist[src]=0;
	for(i=0;i<n;i++)//for 3
	{
		if(i==src)
			continue;
		min=999;
		for(j=0;j<n;j++)//for 1
		{
			if((visited[j]==0) && (min>dist[j]))
			{
				min=dist[j];
				u=j;
			}
		}//end for1

		visited[u]=1;
		for(j=0;j<n;j++)//for 2
		{
			if(visited[j]==0)
			{
				if(dist[j]>dist[u]+cost[u][j])
					dist[j]=dist[u]+cost[u][j];
			}
		}//end for 2
	}//for 3
}


int main()
{	float start,end,t;
	int n,cost[10][10],dist[10]={0},i,j,src;
	cout<<"Enter no. of vertics:\n";
	cin>>n;
	cout<<"Enter adjacency matrix:\n";
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
	{
		//cout<<"enter["<<i<<"]"<<"["<<j<<"]";
		cin>>cost[i][j];

	}
	}
	cout<<"Enter source vertex:\n";
	cin>>src;
	start=clock();
	dij(src,cost,dist,n);
	end=clock();
	cout<<"The shortest path from "<<src<<" :\n";
	for(i=0;i<n;i++)
	{
		cout<<"to "<<i<<" : "<<dist[i]<<endl;

	}
	cout<<"Time taken = "<<(end-start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
/*Output
Enter no. of vertics:
4
Enter adjacency matrix:
0 5 999 10
5 0 7 999
999 7 0 6
10 999 6 0
Enter source vertex:
1
The shortest path from 1 :
to 0 : 5
to 1 : 0
to 2 : 7
to 3 : 13
Time taken = 4e-06
*/
