#include<iostream>
#include<stdlib.h>
using namespace std;
int count,d,x[10],w[10];

void subset(int weightSofar,int k,int remaining)
{
	x[k]=1;int i;
	if(weightSofar+w[k]==d)
	{
		cout<<"\nSol "<<++count<<": ";
		for(i=0;i<=k;i++)
		{
			if(x[i]==1)
			{
				cout<<w[i]<<"\t";
			}

		}
		return;
	}

	else if(weightSofar+w[k]+w[k+1]<=d)
	{
		subset(weightSofar+w[k],k+1,remaining-w[k]);

	}

	if(weightSofar+w[k+1]<=d && weightSofar+remaining-w[k]>=d)
	{
		x[k]=0;
		subset(weightSofar,k+1,remaining-w[k]);
	}

}




int main()
{
	int i,n,sum=0;
	cout<<"No of elememts : ";
	cin>>n;
	cout<<"\nElements in asc order : \n";
	for(i=0;i<n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	}
	cout<<"Enter sum : \n";
	cin>>d;

	subset(0,0,sum);
	cout<<endl;
	return 0;
}

/*Output
No of elememts : 4

Elements in asc order :
7 11 13 24
Enter sum :
31

Sol 1: 7	11	13
Sol 2: 7	24
*/
