#include<iostream>
using namespace std;

void bfs(int a[][20],int n,int source)
{
	int k,f,r,u,v,i;
	int q[50],t[20][20],visit[20];
	for(i=1;i<=n;i++)
		visit[i]=0;
	f=r=k=0;
	visit[source]=1;
	q[r]=source;
	while(f<=r)
	{
		u=q[f];
		f++;
		for(v=1;v<=n;v++)
		{
			if((a[u][v]==1) && (visit[v]==0))
			{
				visit[v]=1;
				r++;
				q[r]=v;
				}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(visit[i]==1)
			cout<<i<<" is reachable from "<<source<<endl;
		else
			cout<<i<<" is not reachable from "<<source<<endl;
	}
}

int main()
{
	int a[20][20],source,i,j,n;
	cout<<"Enter no. of vertices:\n";
	cin>>n;
	cout<<"Enter adjacency matrix:\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	cout<<"Enter source vertex:";
	cin>>source;
	bfs(a,n,source);

	return 0;
}

/*Output
Enter no. of vertices:
7
Enter adjacency matrix:
0 1 1 1 1 0 0
1 0 0 0 0 1 0
1 0 0 0 0 0 1
1 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0
0 0 1 0 1 0 0
Enter source vertex:1
1 is reachable from 1
2 is reachable from 1
3 is reachable from 1
4 is reachable from 1
5 is reachable from 1
6 is reachable from 1
7 is reachable from 1
*/
