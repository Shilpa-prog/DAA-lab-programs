package term6b;

import java.util.Scanner;

public class Knapsack {
	static int size=1000,n,j;
	static float max,sum=0;
		void knap(int W,int wei[],int val[]) {
		while(W>=0) {
			 max=0;
			for(int i=0;i<n;i++) {
				if((float)val[i]/(float) wei[i]>max) {
					max=((float)val[i]/(float)wei[i]);
					 j=i;
					}
				}
			if(wei[j]>W) {
				System.out.println("Weight added to knapsack "+W);
				sum+=W*max;
				W=-1;
			}
			else {
				System.out.println("Weigth added to knapsack "+wei[j]);
				sum+=(float)val[j];
				W=W-wei[j];
				val[j]=0;
			}
		}
		System.out.println("The Maximum Value/Profit is "+sum );
		}
	
	public static void main(String[] args) {
		System.out.println("-------Knapsack Problem ------");
		System.out.println("Enter weight of knapsack ");
		Scanner sc = new Scanner(System.in);
		int W=sc.nextInt();
		int w[]=new int[size];
		int v[]=new int[size];
		System.out.println("Enter number of items ");
		 n=sc.nextInt();
		System.out.println("Enter Weights "+n+" Respective Items");
			for(int i=0;i<n;i++) {
				w[i]=sc.nextInt();
			}
		System.out.println("Enter value of "+n+" Item ");
			for(int i=0;i<n;i++) {
				v[i]=sc.nextInt();
			}
			Knapsack k = new Knapsack();
		    k.knap(W,w,v);	
		sc.close();
	}

}
