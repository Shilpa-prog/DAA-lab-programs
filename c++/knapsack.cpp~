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
	cout<<"the matrix:\n";
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<v[i][j]<<"  ";
		}
		cout<<"\n";
	}
	
	cout<<"the optimal solution is:"<<v[n][m];
	cout<<"\nthe items selected are:";
	for(i=1;i<=n;i++)
		cout<<x[i]<<"  ";
}	

int main()
{
	int i,j,n,m,w[10],p[10];
	cout<<"enter no. of objects in graph:";
	cin>>n;
	cout<<"enter total capacity of graph:";
	cin>>m;
	cout<<"weight of each vertices:";
	for(i=1;i<=n;i++)
		cin>>w[i];
	cout<<"\nprofit of each vertices:";
	for(i=1;i<=n;i++)
		cin>>p[i];

	knapsack(n,m,w,p);
	
	return 0;
}	

























	 										
