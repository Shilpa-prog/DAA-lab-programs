/*
 * Obtain the Topological ordering of vertices in a given digraph.
 */

#include <stdio.h>

#define MAX 10

int main(int argc, char *argv[])
{
	int no, i, j;
	int a[MAX][MAX], indeg[MAX] = {0}, visited[MAX] = {0}, count = 0;

	printf ("Enter The No of Vertices\n");
	scanf("%d", &no);

	printf ("Enter the Adjacency Matrix\n");
	for(i = 0; i < no; i++)
		for (j = 0; j < no; j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j])
				indeg[j]++;
		}

	printf ("Topological sort is :\n");

	while(count < no)
	{
		for(i = 0; i < no; i++)
			if(indeg[i] == 0 && visited[i] == 0)
			{
				printf ("%d\t", i + 1);
				visited[i] = 1;
				count++;
				for (j = 0; j < no; ++j)
					if(a[i][j])
						indeg[j]--;
			}
	}
	return 0;
}

/*Output
Enter The No of Vertices
5
Enter the Adjacency Matrix
0 0 1 0 0
0 0 1 0 0
0 0 0 1 1
0 0 0 0 1
0 0 0 0 0
Topological sort is :
1	2	3	4	5
*/
