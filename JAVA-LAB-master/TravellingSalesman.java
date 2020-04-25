import java.util.Scanner;
class Travel {
int weight[][],n,tour[],finalCost;
final int INF=1000;
Travel()
{
		 Scanner s=new Scanner(System.in);
		 System.out.println("Enter no. of nodes:=>");
		 n=s.nextInt();
		 weight=new int[n][n];
		tour=new int[n-1];
		System.out.println("Enter Adjacency Matrix ");
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		weight[i][j]=s.nextInt();
		System.out.println();
		System.out.println("Starting node assumed to be node 1.");
		eval();
		s.close();
}

public int COST(int curr,int inputSet[],int setSize)
{
		if(setSize==0)
		return weight[curr][0];
		int min=INF;
		int setNextCOST[]=new int[n-1];
		for(int i=0;i<setSize;i++)
		{
		int k=0;
		for(int j=0;j<setSize;j++)
		{
		if(inputSet[i]!=inputSet[j])
		setNextCOST[k++]=inputSet[j];
		}
		int temp=COST(inputSet[i],setNextCOST,setSize-1);
		if((weight[curr][inputSet[i]]+temp) < min)
		{
		min=weight[curr][inputSet[i]]+temp;
}
}
		
return min;
}

public int MIN(int current,int inputSet[],int setSize)
{
			if(setSize==0)
			return weight[current][0];
			int min=INF,minindex=0;
			int setNextCOST[]=new int[n-1];
			for(int i=0;i<setSize;i++)//considers each node of inputSet
			{
			int k=0;
			for(int j=0;j<setSize;j++)
			{
			if(inputSet[i]!=inputSet[j])
			setNextCOST[k++]=inputSet[j];
			}
			int
			temp=COST(inputSet[i],setNextCOST,setSize-1);
			if((weight[current][inputSet[i]]+temp) < min)
			{
			min=weight[current][inputSet[i]]+temp;
			minindex=inputSet[i];
			}
			}
			return minindex;
}
public void eval()
{
		int dummySet[]=new int[n-1];
		for(int i=1;i<n;i++)
		dummySet[i-1]=i;
		finalCost=COST(0,dummySet,n-1);
		constructTour();
}

public void constructTour()
{
			int previousSet[]=new int[n-1];
			int nextSet[]=new int[n-2]; for(int i=1;i<n;i++)
			previousSet[i-1]=i;
			int setSize=n-1;
			tour[0]=MIN(0,previousSet,setSize);
			for(int i=1;i<n-1;i++)
			{
			int k=0;
			for(int j=0;j<setSize;j++)
			{
			if(tour[i-1]!=previousSet[j])
			nextSet[k++]=previousSet[j];
			}
			--setSize;
			tour[i]=MIN(tour[i-1],nextSet,setSize);
			for(int j=0;j<setSize;j++)
			previousSet[j]=nextSet[j];
}
display();
}
public void display()
{
		System.out.println();
		System.out.print("The tour is 1-");
		for(int i=0;i<n-1;i++)
		System.out.print((tour[i]+1)+"-");
		System.out.print("1");
		System.out.println();
		System.out.println("The final cost is "+finalCost);
}
}
class TSP
{
	public static void main(String args[])
	{
			Travel obj=new Travel();
			obj.eval();
	}
}
