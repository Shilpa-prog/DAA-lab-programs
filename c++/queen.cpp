#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int x[10];

int place(int a,int k)
{
	int i;
	x[k]=a;
	for(i=1;i<k;i++)
		if(x[i]==x[k] || abs(i-k)==abs(x[i]-x[k]))
			return 0;
		return 1;

}

void queen(int n)
{
	int k,i,j;
	char q[10][10];
	k=1;
	x[k]=0;

	while(k!=0)
	{
		x[k]+=1;
		while((x[k]<=n) && (place(x[k],k)!=1))
		{
			x[k]+=1;
		}

		if (x[k]<=n)
		{
			if(k==n)
			{
				for(i=1;i<=n;i++)
					for(j=1;j<=n;j++)
						q[i][j]='X';

				cout<<"\n";
				for(i=1;i<=n;i++)
					q[i][x[i]]='Q';

				for(i=1;i<=n;i++)
				{
					for(j=1;j<=n;j++)
						cout<<q[i][j]<<"\t";
					cout<<"\n";
				}

			}
			else
			{
				k++;
				x[k]=0;
			}
		}
		else
			k--;
	}
}

int main()
{
	int n,i,j;
	cout<<"Enter no of queens :\n";
	cin>>n;
	queen(n);
	return 0;
}

/*Output
Enter no of queens :
4

X	Q	X	X
X	X	X	Q
Q	X	X	X
X	X	Q	X

X	X	Q	X
Q	X	X	X
X	X	X	Q
X	Q	X	X
*/
