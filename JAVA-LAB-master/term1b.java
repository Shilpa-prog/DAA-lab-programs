package term1b;
import java.util.*;
public class term1b {
	static int stack[],top=-1;
	public static void main(String[] args) {
		System.out.println("Enter Stack Size ");
		Scanner Sc = new Scanner(System.in);
		int size=Sc.nextInt();
		stack = new int[size];
		System.out.println("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
		System.out.println("\nEnter your Choice  ");
		int choice = Sc.nextInt();
		while(choice!=4)
		{
			if(choice==1)
			{
				System.out.println("\nEnter Element to push ");
				int element =Sc.nextInt();
				if(top==size-1)
					System.out.println("\nStack is full ");
				else
				{
					top=top+1;
					stack[top]=element;
				}
				
			}
			else if(choice==2)
			{
				if(top==-1)
				{
					System.out.println("\nStack is empty ");
					
				}
				else
				{
					System.out.println("\nPopped element is "+stack[top]);
					top--;
				}
			}
			else if(choice==3)
			{
				if(top==-1)
				{
					System.out.println("\nEMPTY STACK ");
					
				}
				else
				{
					System.out.println("\nStack Elements are ");
					for(int i=top;i>=0;i--)
					{
						System.out.println(stack[i]);
					}
				}
			}
		
			else {	
				System.out.println("\nEnter Correct Choice \n");
			}
				System.out.println("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
				System.out.println("\nEnter your Choice  ");
				choice = Sc.nextInt();
				
			
				
		}
		Sc.close();
	}

}
