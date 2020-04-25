import java.util.Scanner;


public class QuickSort {
	static int a[];
	
	static void qsort(int left, int right)
	{
		if(left<right)
		{
			int p = partition(left, right);
			qsort(left, p-1);
			qsort(p+1, right);
		}
	}
	
	
	static int partition(int low, int high)
	{
		int pivot = a[high];
		int pindex=low;
		for(int i=low;i<=high-1;i++)
		{
			if(a[i]<=pivot)
			{
				int temp = a[pindex];
				a[pindex] = a[i];
				a[i] = temp;
				
				pindex++;
			}
		}
		
		int temp = a[pindex];
	a[pindex] = a[high];
	a[high] = temp;
		
		return pindex;
	}
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n, i;
		System.out.println("Enter the no. of elements: ");
		n = s.nextInt();
		a = new int[n];		
		System.out.println("The Random Numbers are:");
		for (i = 0; i < n; i++) 
		{
			a[i] = (int) (Math.random() * 100);
			System.out.print(a[i]+" ");
		}
		long startTime = System.nanoTime();
		qsort( 0, n-1);
		long endTime = System.nanoTime();
		long duration = (endTime - startTime);

		System.out.println("\nThe Sorted Numbers are:");
		for (i = 0; i < n; i++) {
			System.out.print(a[i]+" ");
		}
		System.out.println("\nTime taken is "+ duration/1000+" microseconds" );
	}

}
