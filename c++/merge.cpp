#include<iostream>
#include<omp.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int *a;
void merge(int low,int mid,int high)
{
	int i,j,k;
	long int b[60000];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}//end while

	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
	for(i=low;i<k;i++)
		a[i]=b[i];
}


int mergesort(int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(high+low)/2;
		#pragma omp task
		{
			mergesort(low,mid);
		}
		#pragma omp task
		{
			mergesort(mid+1,high);
		}
		merge(low,mid,high);
	}
}


int main()
{
	int i,n;
	double start,end;
	cout<<"Enter size of array :\n";
	cin>>n;
	a=new int[n];
	cout<<"Enter "<<n<<" elements\n";
	omp_set_num_threads(2);
	srand(0);
	for(i=0;i<n;i++)
	{
		a[i]=rand()%n;
		cout<<a[i]<<"\t";
	}
	start=omp_get_wtime();
	mergesort(0,n-1);
	end=omp_get_wtime();
	cout<<"\nSorted array : \n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<"\nTime taken = "<<(end-start)<<endl;
	return 0;
}

/*Output
Enter size of array :
10
Enter 10 elements
3	6	7	5	3	5	6	2	9	1
Sorted array :
1	2	3	3	5	5	6	6	7	9
Time taken = 2.305e-05
*/
