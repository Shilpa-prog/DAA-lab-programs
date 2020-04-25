/*1. Sort a given set of elements using the Quicksort method and determine the time required to
sort the elements. Repeat the experiment for different values of n, the number of elements in the list to
be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be
generated using the random number generator.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define SWAP(a,b,temp)(temp = a , a = b, b = temp)

int partition(int a[], int low, int high);
void quicksort(int a[], int low, int high);

int main()
{
     int i,n,a[250000];

     float start,end,t;

     printf("Enter the number of elements :\n");
     scanf("%d",&n);

     printf("\nInitialising array with random numbers to sort\n");
     for(i = 0; i<n;i++)
          a[i] = rand()%10;

     printf("\n\nBefore sorting , the array is : \n");
     for(i = 0; i<n;i++)
          printf("%d\t",a[i]);

     start = clock();
     quicksort(a,0,n-1);
     end = clock();

     printf("\n\nAfter sorting , the array is : \n\n");
     for(i = 0; i<n;i++)
          printf("%d\t",a[i]);

     //Time complexity
     t = (end-start)/CLOCKS_PER_SEC;

     printf("\nTime complexity : %f\n",t);
     return 0;
}

int partition(int a[], int low, int high)
{
     int i,j,temp;
     i = low;
     j = high+1;

     while(i<j)
     {
          do
          {
               ++i;
          }while(a[i]<=a[low]);

          do
          {
               --j;
          }while(a[j]>a[low]);

          if(i<j)
               SWAP(a[i],a[j],temp);
     }
     SWAP(a[j],a[low],temp);
     return j;
}

void quicksort(int a[], int low,int high)
{
     int s;
     if(low < high)
     {
          s = partition(a,low,high);
          quicksort(a,low,s-1);
          quicksort(a,s+1,high);
     }

}

/*Output
Enter the number of elements :
10

Initialising array with random numbers to sort


Before sorting , the array is :
3	6	7	5	3	5	6	2	9	1

After sorting , the array is :

1	2	3	3	5	5	6	6	7	9
Time complexity : 0.002355
*/
