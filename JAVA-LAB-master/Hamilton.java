package Hamm;
import java.util.*;
	class Hammm
	{
		private int mat[][],x[],n;
		public Hammm()
		{
			Scanner sc = new Scanner(System.in);
			System.out.println("Enter the number of nodes");
			n=sc.nextInt();
			x=new int[n];
			x[0]=0;
			for (int i=1;i<n; i++)
				x[i]=-1;
			mat=new int[n][n];
			System.out.println("Enter the matacency matrix");
			for (int i=1;i<n; i++)
				for (int j=1; j<n; j++)
					mat[i][j]=sc.nextInt();
			sc.close();
		}	
		
		public void nextValue (int v)
		{
			int i=0;
			while(true)
			{ 
				x[v]=x[v]+1;
			if (x[v]==n)
				x[v]=-1;
			if (x[v]==-1)
				return;
			if (mat[x[v-1]][x[v]]==1)
				for (i=0; i<v; i++)
					if (x[i]==x[v])
						break;
			if (i==v)
				if (v<n-1 || v==n-1 && mat[x[n-1]][0]==1)
					return;
			}
		}
		
		public void getCycle(int v)
		{
			while(true)
			{
				nextValue(v);
				if (x[v]==-1)
					return;
				if (v==n-1)
				{
					System.out.println("\nSolution : ");
					for (int i=0; i<n; i++)
						System.out.print((x[i]+1)+" ");
					System.out.println(1);
				}
				else getCycle(v+1);
			}
		}
	}
	class Hamil
	{
		public static void main(String args[])
		{
			Hammm obj=new Hammm();
			obj.getCycle(1);
		}
	}
