/*
 *Implement All-Pairs Shortest Paths Problem using Floyd's algorithm.
 *Parallelize this algorithm, implement it using OpenMP and
 *determine the speed-up achieved.
 */

 #include <stdio.h>
 #include <omp.h>

 #define min(a, b)(a < b ? a : b)

 void floyd(int a[10][10],int n)
 {
   int thread_id, i, j, k;
   float s, e;
   s=omp_get_wtime();
   omp_set_num_threads(2);
   #pragma omp parallel for shared(a) private(i, j, k)
   for (k = 0; k < n; k++)
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
      {
        thread_id=omp_get_thread_num();
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        printf("Thread %d : a[%d][%d] = %d\n", thread_id, i, j, a[i][j]);
      }
    e=omp_get_wtime();
    printf("Shortest path matrix is\n");
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
        printf("%d\t",a[i][j]);
      printf("\n");
    }
    printf("Time taken %f\n",(e-s) );
 }

int main(int argc, char const *argv[])
{
  int size,a[10][10],i,j;
  printf("Enter the size\n");
  scanf("%d",&size);
  printf("Enter the Elements\n");
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      scanf("%d",&a[i][j]);
  floyd(a,size);
  return 0;
}

/*Output
Enter the size
4
Enter the Elements
0 999 3 999
2 0 999 999
999 7 0 1
6 999 999 0
Thread 0 : a[0][0] = 0
Thread 0 : a[0][1] = 999
Thread 0 : a[0][2] = 3
Thread 0 : a[0][3] = 999
Thread 0 : a[1][0] = 2
Thread 0 : a[1][1] = 0
Thread 0 : a[1][2] = 5
Thread 0 : a[1][3] = 999
Thread 0 : a[2][0] = 999
Thread 0 : a[2][1] = 7
Thread 0 : a[2][2] = 0
Thread 0 : a[2][3] = 1
Thread 0 : a[3][0] = 6
Thread 0 : a[3][1] = 999
Thread 0 : a[3][2] = 9
Thread 0 : a[3][3] = 0
Thread 0 : a[0][0] = 0
Thread 0 : a[0][1] = 999
Thread 0 : a[0][2] = 3
Thread 0 : a[0][3] = 999
Thread 0 : a[1][0] = 2
Thread 0 : a[1][1] = 0
Thread 0 : a[1][2] = 5
Thread 0 : a[1][3] = 999
Thread 0 : a[2][0] = 9
Thread 0 : a[2][1] = 7
Thread 0 : a[2][2] = 0
Thread 0 : a[2][3] = 1
Thread 0 : a[3][0] = 6
Thread 0 : a[3][1] = 999
Thread 0 : a[3][2] = 9
Thread 0 : a[3][3] = 0
Thread 1 : a[0][0] = 0
Thread 1 : a[0][1] = 10
Thread 1 : a[0][2] = 3
Thread 1 : a[0][3] = 4
Thread 1 : a[1][0] = 2
Thread 1 : a[1][1] = 0
Thread 1 : a[1][2] = 5
Thread 1 : a[1][3] = 6
Thread 1 : a[2][0] = 9
Thread 1 : a[2][1] = 7
Thread 1 : a[2][2] = 0
Thread 1 : a[2][3] = 1
Thread 1 : a[3][0] = 6
Thread 1 : a[3][1] = 16
Thread 1 : a[3][2] = 9
Thread 1 : a[3][3] = 0
Thread 1 : a[0][0] = 0
Thread 1 : a[0][1] = 10
Thread 1 : a[0][2] = 3
Thread 1 : a[0][3] = 4
Thread 1 : a[1][0] = 2
Thread 1 : a[1][1] = 0
Thread 1 : a[1][2] = 5
Thread 1 : a[1][3] = 6
Thread 1 : a[2][0] = 7
Thread 1 : a[2][1] = 7
Thread 1 : a[2][2] = 0
Thread 1 : a[2][3] = 1
Thread 1 : a[3][0] = 6
Thread 1 : a[3][1] = 16
Thread 1 : a[3][2] = 9
Thread 1 : a[3][3] = 0
Shortest path matrix is
0	10	3	4
2	0	5	6
7	7	0	1
6	16	9	0
Time taken 0.000977
*/
