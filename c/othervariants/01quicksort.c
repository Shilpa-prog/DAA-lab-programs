/*
NOTE :- this program is designed to work with testbench script

Sort a given set of elements using the Quicksort method and
determine the time required to sort the elements. Repeat the
experiment for different values of n, the number of elements in the
list to be sorted and plot a graph of the time taken versus n.
The elements can be read from a file or can be generated using the
random number generator.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *a,int l,int h)
{
  int i,j,temp;
  i=low;
  j=high;
  while (i<j)
  {
    do {++i;} while(a[i]<a[low]);
    do {++j;} while(a[j]<a[low]);
    if (i<j)
    {
      temp=a[i];a[i]=a[j];a[j]=temp;
    }
  }
  temp=a[i];
  a[j]=a[low];
  a[low]=temp;
  return j;
}

void quicksort(int *a,int l,int h)
{
  int s;
  if (l<h)
  {
    s=partition(a,l,h);
    quicksort(a,l,s-1);
    quicksort(a,s,h);
  }
}

int main(int argc, char const *argv[])
{
  int i,n;
  n=atoi(argv[1]);
  float s,e;
  int a[n];
  for (i = 0; i < n; i++)
  {
    a[i]=rand()%100000;
  }
  s=clock();
  quicksort(a,0,n-1);
  e=clock();
  printf("\n%d\t%lf\n",n,(e-s)/CLOCK_PER_SEC);
  return 0;
}
