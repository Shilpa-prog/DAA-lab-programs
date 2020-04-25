#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define SWAP(a,b,temp)(temp = a, a = b, b = temp)

int partition(int a[],int low,int high)
{
	int p=a[low],temp;
	int i,j;
	i=low;j=high+1;
	while(i<j)
	{
		do
		{
			++i;
		}while(a[i]<p);

		do
		{
			j--;
		}while(a[j]>p);

		if(i<j)
		{
			SWAP(a[i],a[j],temp);
			/*temp=a[i];
			a[i]=a[j];
			a[j]=temp;*/
		}
	}//end while

	SWAP(a[j],a[low],temp);
	/*temp=a[j];
	a[j]=a[low];
	a[low]=temp;*/

	return j;
	}


void quicksort(int a[],int low,int high)
{
	int s;
	if(low<high)
	{
		s = partition(a,low,high);
		quicksort(a,low,s-1);
		quicksort(a,s+1,high);

	}
}

int main()
{
	float start,end,t;
	int p,n,i;
	cout<<"Enter n : ";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%50;

	start=clock();
	quicksort(a,0,n-1);
	end=clock();
	t=(end-start)/CLOCKS_PER_SEC;
	cout<<"\n\n";

	for(i=0;i<n;++i)
		cout<<a[i]<<"\t";

	cout<<"\nTime taken = "<<t<<endl;

	return 0;
}

/*Output
Enter n : 10

15	21	27	33	35	36	36	42	43	49
Time taken = 3e-06
*/
