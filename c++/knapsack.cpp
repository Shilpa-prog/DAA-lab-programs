#include<iostream>
#include<stdlib.h>
using namespace std;

int v[10][10],x[10];

int max(int a,int b)
{
	return ((a>b)?a:b);
}

void knapsack(int n,int m,int w[10],int p[10])
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
				v[i][j]=0;
			else if(w[i]>j)
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	for(i=1;i<n;i++)
		x[i]=0;
	i=n;
	j=m;
	while( (i!=0) && (j!=0))
	{
		if(v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i=i-1;
	}
	cout<<"\nThe matrix : \n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<v[i][j]<<"\t";
		}
		cout<<"\n";
	}

	cout<<"\nThe optimal solution is = "<<v[n][m]<<endl;
	cout<<"\nThe items selected are : ";
	for(i=1;i<=n;i++)
		cout<<x[i]<<"\t";
	cout<<endl;
}

int main()
{
	int i,j,n,m,w[10],p[10];
	cout<<"Enter no. of objects in the graph :\n";
	cin>>n;
	cout<<"Enter total capacity of graph :\n";
	cin>>m;
	cout<<"Weight of each vertex:\n";
	for(i=1;i<=n;i++)
		cin>>w[i];
	cout<<"\nProfit of each vertex :\n";
	for(i=1;i<=n;i++)
		cin>>p[i];

	knapsack(n,m,w,p);

	return 0;
}

/*Output
Enter no. of objects in the graph :
4
Enter total capacity of graph :
5
Weight of each vertex:
2 1 3 2

Profit of each vertex :
12 10 20 15

The matrix :
0	0	0	0	0	0
0	0	12	12	12	12
0	10	12	22	22	22
0	10	12	22	30	32
0	10	15	25	30	37

The optimal solution is = 37

The items selected are : 1	1	0	1
*/
