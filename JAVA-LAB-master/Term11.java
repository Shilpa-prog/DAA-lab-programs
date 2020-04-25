package term11;
import java.util.Scanner;
import java.lang.Math;

public class Subset {
	static int x[]=new int[100];
	public  void subset(int num, int n) {
		for(int i=1;i<=n;i++)
			x[i]=0;
		for(int i=n;num!=0;i--) {
			x[i]=num%2;
			num/=2;
		}
	}
	public static void main(String[] args) {
		int n,d,sum,j,flag=0;
		int a[]=new int[100];
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of elements ");
		n=sc.nextInt();
		System.out.println("Enter the elements ");
		for(int i=1;i<=n;i++) 
			a[i]=sc.nextInt();
		System.out.println("Enter val of d ");
		d=sc.nextInt();
		if(d>0) {
			for(int i=1;i<=Math.pow(2,n)-1;i++) {
				Subset s=new Subset();
				s.subset(i,n);
				sum=0;
			for(j=1;j<=n;j++) {
				if(x[j]==1) 
					sum+=a[j];
					}
				if(d==sum) {
					flag=1;
					System.out.print("Subset is {");
					for(j=1;j<=n;j++)
						{
						if(x[j]==1)
							System.out.print(a[j]+" ");
						}
					System.out.print("} == "+sum);
					System.out.println();
				}
		 }
			if(flag==1)
				System.out.println("No Answer");
		sc.close();
		}
	}
}

