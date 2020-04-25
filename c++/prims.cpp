#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

void prims(int n,int cost[][10])
{
	int min=999,source=1,i,j,k,p[10],u,q=0;
	int select[10][2],visit[10],sum=0,count=0;
	visit[source]=1;
	k=0;
	while(count<n-1)
	{
		min=999;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if((visit[i]==1) && (visit[j]!=1))
					if(cost[i][j]<min)
					{
						min=cost[i][j];
						u=j;
						p[u]=i;
					}

		visit[u]=1;
		select[q][0]=u;
		select[q][1]=p[u];
		sum=sum+cost[u][p[u]];
		count++;
		q++;
	}// end while

	if(sum<999)
	{
		cout<<"Spanning tree exists "<<endl;
		for(i=0;i<n-1;i++)
			cout<<select[i][0]<<"\t"<<select[i][1]<<endl;
		cout<<"The cost of the path is :"<<sum<<endl;
	}
	else
		cout<<"Path does not exist";

}
int main()
{
	int i,j,k,cost[10][10],n;
	cout<<"Enter n :\n";
	cin>>n;
	cout<<"Enter matrix :\n";
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			cin>>cost[i][j];
	prims(n,cost);
	return 0;
}

/*Output
Enter n :
6
Enter matrix :
0 60 10 999 999 999
60 0 999 20 40 70
10 999 0 999 999 50
999 20 999 0 999 80
999 40 999 999 0 30
999 70 50 80 30 0
Spanning tree exists
3	1
6	3
5	6
2	5
4	2
The cost of the path is :150
*/
