// Nqueens problem
#include <stdio.h>
#include <stdlib.h>

const int MAX = 10;

int SolnCount =0;

int fnCheckPlace(int KthQueen, int ColNum, int row[MAX])
{
  int i;
  for(i=0; i<KthQueen; ++i)
  {
    if(row[i] == ColNum || abs(row[i]-ColNum) == abs(i-KthQueen))
    return 0;
  }
  return 1;
}

void fnChessBoardShow(int n, int row[MAX])
{
  printf("\nSolution # %d \n\n",SolnCount+1);
  int i, j;
  for (i=0; i<n; i++)
  {
    for (j=0; j<n; j++)
    {
      if (j == row[i])
      printf("Q ");
      else
      printf("# ");
    }
    printf("\n");
  }
  printf("\n");
}

void NQueen(int k,int n, int row[MAX])
{
  int i;
  for(i=0;i<n;i++)
  {
    if(fnCheckPlace(k,i,row) == 1)
    {
      row[k] = i;
      if(k == n-1)
      {
        fnChessBoardShow(n,row);
        SolnCount++;
      }
      NQueen(k+1, n, row);
    }
  }
}

int main(int argc, char const *argv[])
{
  int n;
  int row[MAX];
  printf ("Enter the size of the board\n");
	scanf("%d", &n);
  NQueen(0,n,row);
  if (SolnCount == 0)
    printf("No solution exists for the given problem instance.\n");
  else
    printf("Number of solution for the given problem instance is : %d \n",SolnCount);
  return 0;
}

/*Output
Enter the size of the board
4

Solution # 1

# Q # #
# # # Q
Q # # #
# # Q #


Solution # 2

# # Q #
Q # # #
# # # Q
# Q # #

Number of solution for the given problem instance is : 2
*/
