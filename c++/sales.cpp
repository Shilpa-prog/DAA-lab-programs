#include<iostream>
using namespace std;

int a[10][10],visited[10],n,cost=0,sum=0,lastcity=0,vs[10];

void get()
{
		int i,j;
		cout<<"Enter no of cities:";
		cin>>n;
		cout<<"Enter the cost matrix:\n";
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				cin>>a[i][j];
			visited[i]=0;
		}
		cout<<"The cost matrix is :\n";
		for(i=1;i<=n;i++)
		{
			cout<<"\n\n";
			for(j=1;j<=n;j++)
				cout<<a[i][j]<<"\t";
		}
}

int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
	for(i=1;i<=n;i++)
	{
		if((a[c][i]!=0) && (visited[i]==0))
			if(a[c][i]<min)
			{
				min=a[i][1]+a[c][i];
				kmin=a[c][i];
				nc=i;

			}
	}
	if(min !=999)
		cost+=kmin;
	return nc;
}



void mincost(int city)
{
	int i,ncity;
	visited[city]=1;
	cout<<city<<"->";
	ncity=least(city);
	if (ncity==999)
	{
		ncity=1;
		cout<<ncity;
		cost+=a[city][ncity];
		return;
	}
	mincost(ncity);
}

void nearest_neighbour(int city)
{
	int min,j,i,u;
	vs[city]=1;
	cout<<city<<"->";
	u=city;
	for(j=1;j<=n;j++)
	{
		min=999;
		for(i=1;i<=n;i++)
		{
			if((vs[i]==0)&& (a[city][i] !=0))
				if(a[city][i] < min)
				{
					min=a[city][i];
					u=i;
				}
			city=u;
		}
		vs[u]=1;
		if (min != 999)
		{
			sum+=min;
			cout<<u<<"->";
		}
	}
	lastcity=u;
}


void put()
{
	cout<<"\nMin cost"<<cost<<endl;
}

int main()
{
	float ratio;
	get();
	cout<<"\nThe path is:";
	mincost(1);
	put();
	cout<<"\nThe path using algorithm:";
	nearest_neighbour(1);
	cout<<"1";
	sum+=a[lastcity][1];
	cout<<"\nMin cost is:"<<sum;
	ratio=(float)sum/cost;
	cout<<"\nThe accurate ratio : "<<ratio<<endl;
	return 0;
}

/*output
Enter no of cities:4
Enter the cost matrix:
0 10 15 20
5 0 9 10
6 13 0 2
8 8 9 0
The cost matrix is :


0	10	15	20

5	0	9	10

6	13	0	2

8	8	9	0
The path is:1->2->4->3->1
Min cost35

The path using algorithm:1->4->2->3->1
Min cost is:25
The accurate ratio : 0.714286*/
