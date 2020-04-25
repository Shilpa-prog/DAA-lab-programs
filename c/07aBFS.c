/*
  Print all the nodes reachable from a given starting node in a digraph using BFS method.
*/

#include <stdio.h>
#include <stdlib.h>

int a[20][20], src, n,vis[20];

void Bfs()
{
  int i, f, r=0, u, v, q[50];
  q[r] = src;
  vis[src] = 1;
  for (f = 0, r = 0; f <=r ; ++f)
  {
    u = q[f];
    for (v = 1; v <= n; v++)
    {
      if ((a[u][v] == 1) && (vis[v] == 0))
      {
        vis[v] = 1;
        q[++r] = v;
      }
    }
  }
  for (i = 1; i <= n; i++)
  {
      if (vis[i] == 1)
        printf("%d ---> %d\n",src,i);
      else
        printf("%d ---> %d is not possible\n",src,i);
  }
}

int main(int argc, char const *argv[])
{
  int i, j;
  printf("Implementation of BFS traversal \nEnter the number of verticies \n : ");
  scanf("%d",&n);
  printf("Enter the Adjacency matrix\n");
  for (i = 1; i <= n; ++i)
    for (j = 1; j<= n; j++)
      scanf("%d",&a[i][j]);
  printf("Enter the Source vertex\n");
  scanf("%d",&src);
	Bfs();
  return 0;
}
/*Output

Implementation of BFS traversal
Enter the number of verticies
 : 6
Enter the Adjacency matrix
0 1 1 1 0 0
0 0 0 0 1 0
0 0 0 0 1 1
0 0 0 0 0 1
0 0 0 0 0 0
0 0 0 0 1 0
Enter the Source vertex
1
1 ---> 1
1 ---> 2
1 ---> 3
1 ---> 4
1 ---> 5
1 ---> 6
*/
