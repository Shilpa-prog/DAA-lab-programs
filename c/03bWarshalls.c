/*
  Compute the transitive closure of a given directed graph using Warshall's algorithm.
 */

#include <stdio.h>
#include <math.h>

#define MAX(a, b) (a > b ? a : b)

void warshal(int p[10][10], int n)
{
	int i, j, k;
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				p[i][j] = MAX(p[i][j], p[i][k] * p[k][j]);
}

void main()
{
	int p[10][10] = {0}, n, i, j;
	printf("Enter the size of matrix\n");
	scanf("%d", &n);
	printf ("Enter the Adjacency matrix\n");
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d",&p[i][j]);
	warshal(p,n);
	printf("\n Transitive closure: \n");
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
			printf("%d\t", p[i][j]);
		printf("\n");
	}
}

/*Output
Enter the size of matrix
4
Enter the Adjacency matrix
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0

 Transitive closure:
1	1	1	1
1	1	1	1
0	0	0	0
1	1	1	1
*/
