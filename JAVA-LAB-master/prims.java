package term9;

import java.util.Scanner;

public class Term9 {

	public static void main(String[] args) {
		int n=100;
		int size,i,j;
		int u=0,v=0;
		int sum=0;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Size of Matrix ");
		 size=sc.nextInt();
		int a[][] =new int[n][n];
		int visited[] = new int[n];
		System.out.println("Enter the Adjacency matrix ");
			for(i=1;i<=size;i++) {
				for(j=1;j<=size;j++) {
					a[i][j]=sc.nextInt();
				}
			}
			for(i=1;i<=size;i++){
				visited[i]=0;
			}
		System.out.println("Enter the Source ");
		int source=sc.nextInt();
		visited[source]=1;
		int counter=1;
		while(counter<=size) {
			int mini=99;
			for(int p=1;p<=size;p++) {
				for(int q=1;q<=size;q++) {
					if(visited[p]==1 && visited[q]==0) {
						if(p!=q && a[p][q]<mini) 
						{
							mini=a[p][q];
							 u=p;
							 v=q;
						}
					}
				}
			}
			visited[v]=1;
			counter++;
			if(mini!=99) {
			System.out.println(u+"--->"+v+" = "+mini);
			sum=sum+mini;
		}
			}
		System.out.println("Minimum Spanning Tree "+sum);
		
		
			sc.close();
	}

}
