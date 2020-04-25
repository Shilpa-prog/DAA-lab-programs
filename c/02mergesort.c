/*2. Using OpenMP, implement a parallelized Merge Sort algorithm to sort a given set of elements
and determine the time required to sort the elements. Repeat the experiment for different values of n,
the number of elements in the list to be sorted and plot a graph of the time taken versus n.
The elements can be read from a file or can be generated using the random number generator.
*/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int a[250000],b[250000];

void merge(int low, int mid , int high);
void mergesort(int low, int high);

int main()
{
    int i,n;
    float start,end,t;

    printf("Enter size of the array :\n");
    scanf("%d",&n);

    printf("\nInitialising array with random numbers to sort\n");
    for(i = 0; i<n;i++)
        a[i] = rand()%10;

    omp_set_num_threads(1);
    srand(0);

    printf("\nBefore sorting , the array is : \n");
    for(i = 0; i<n;i++)
        printf("%d\t",a[i]);

    start = omp_get_wtime();
    mergesort(0,n-1);
    end = omp_get_wtime();

    printf("\n\nAfter sorting , the array is : \n\n");
    for(i = 0; i<n;i++)
        printf("%d\t",a[i]);

    t = end - start;
    printf("\nTime elapsed : %f\n",t);
    return 0;
}

void merge(int low, int mid , int high)
{
    int i,j,k;

    i = k = low;
    j = mid +1;

    while((i<=mid) && (j<=high))
    {
        if(a[i]<a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while(i<=mid)
    {
        b[k++] = a[i++];
    }
    while(j<=high)
    {
        b[k++] = a[j++];
    }

    for(i = low; i<k; i++)
        a[i] = b[i];
}

void mergesort(int low, int high)
{
    int mid;
    if(low<high)
    {
        mid = (low+high)/2;

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

/*Output
Enter size of the array :
10

Initialising array with random numbers to sort

Before sorting , the array is :
3	6	7	5	3	5	6	2	9	1

After sorting , the array is :

1	2	3	3	5	5	6	6	7	9
Time elapsed : 0.000000
*/
