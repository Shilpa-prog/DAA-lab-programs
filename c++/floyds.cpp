#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;


int min(int a,int b)
{
	return (a<b?a:b);
}


void floyd(int a[][10],int n)
{
	int b[10][10],threadId,i,j,k;
	double startTime,endTime;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=a[i][j];

	startTime= omp_get_wtime();
	omp_set_num_threads(2);
	#pragma omp parallel for shared(b) private(i,j,k)
	for(k=0;k<n;k++)
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				threadId=omp_get_thread_num();
				b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
				cout<<"thread "<<threadId<<" = "<<"b["<<i<<"]"<<"["<<j<<"]"<<" = "<<b[i][j]<<endl;
			}
			endTime=omp_get_wtime();
			cout<<"\nAll pairs shortest path matrix:\n";
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<b[i][j]<<"\t";
				}
				cout<<"\n";
			}
			cout<<"\nTime elapsed = "<<endTime-startTime<<endl;
			return ;
}

int main()
{
	int threadId,i,j,n,a[10][10];
	cout<<"Enter no. of nodes:";
	cin>>n;
	cout<<"Enter distance matrix:\n";
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>a[i][j];

	floyd(a,n);
	return 0;
}

/*Output
Enter no. of nodes:4
Enter distance matrix:
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0
thread thread 11 = b[0] = b[[00]][ = 00] = 0
thread 0 = b[0][1] = 999

thread 1 = b[0][1] = 10
thread 1 = b[0][2] = 3
thread 1 = b[0][3] = 4
thread 1 = b[1][0] = 2
thread 1 = b[1][1] = 0
thread 1 = b[1][2] = 999
thread 1 = b[1][3] = 999
thread 1 = b[2][0] = 999
thread 1 = b[2][1] = 7
thread 1 = b[2][2] = 0
thread 1 = b[2][3] = 1
thread 1 = b[3][0] = 6
thread 1 = b[3][1] = 999
thread 1 = b[3][2] = 999
thread 1 = b[3][3] = 0
thread 1 = b[0][0] = 0
thread 1 = b[0][1] = 10
thread 1 = b[0][2] = 3
thread 1 = b[0][3] = 4
thread 1 = b[1][0] = 2
thread 1 = b[1][1] = 0
thread 1 = b[1][2] = 999
thread 1 = b[1][3] = 999
thread 1 = b[2][0] = 7
thread 1 = b[2][1] = 7
thread 1 = b[2][2] = 0
thread 1 = b[2][3] = 1
thread 1 = b[3][0] = 6
thread 1 = b[3][1] = 999
thread 1 = b[3][2] = 999
thread 1 = b[3][3] = 0
thread 0 = b[0][2] = 3
thread 0 = b[0][3] = 4
thread 0 = b[1][0] = 2
thread 0 = b[1][1] = 0
thread 0 = b[1][2] = 5
thread 0 = b[1][3] = 6
thread 0 = b[2][0] = 7
thread 0 = b[2][1] = 7
thread 0 = b[2][2] = 0
thread 0 = b[2][3] = 1
thread 0 = b[3][0] = 6
thread 0 = b[3][1] = 16
thread 0 = b[3][2] = 9
thread 0 = b[3][3] = 0
thread 0 = b[0][0] = 0
thread 0 = b[0][1] = 10
thread 0 = b[0][2] = 3
thread 0 = b[0][3] = 4
thread 0 = b[1][0] = 2
thread 0 = b[1][1] = 0
thread 0 = b[1][2] = 5
thread 0 = b[1][3] = 6
thread 0 = b[2][0] = 7
thread 0 = b[2][1] = 7
thread 0 = b[2][2] = 0
thread 0 = b[2][3] = 1
thread 0 = b[3][0] = 6
thread 0 = b[3][1] = 16
thread 0 = b[3][2] = 9
thread 0 = b[3][3] = 0

All pairs shortest path matrix:
0	10	3	4
2	0	5	6
7	7	0	1
6	16	9	0

Time elapsed = 0.00154571
*/
