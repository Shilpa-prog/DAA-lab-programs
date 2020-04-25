#include<iostream>
using namespace std;
int vis[10];

int dfs(int a[][20],int n,int source)
{
	int i,j;
	vis[source]=1;
	for(j=1;j<=n;j++)
	{
		if(vis[j]==0 && a[source][j]==1)
			dfs(a,n,j);
	}
	for(j=1;j<=n;j++)
		if(vis[j]==0)
			return 0;
	return 1;
}

int main()
{
	int i,j,source,a[20][20],n,ans;
	cout<<"Enter no of vertices:\n";
	cin>>n;
	cout<<"Enter adjacency matrix:\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];

	cout<<"Enter source:\n";
	cin>>source;

	ans=dfs(a,n,source);
	if(ans==1)
		cout<<"\nGraph is connected.\n";
	else
		cout<<"\nGraph is not connected.\n";
	return 0;
}

/*Output
Enter no of vertices:
7
Enter adjacency matrix:
0 1 1 1 1 0 0
1 0 0 0 0 1 0
1 0 0 0 0 0 1
1 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 1 0 0 0
0 0 1 0 1 0 0
Enter source:
1

Graph is connected.
*/
