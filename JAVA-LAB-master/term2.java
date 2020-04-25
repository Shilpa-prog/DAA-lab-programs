package term2;

import java.util.Scanner;
import java.util.StringTokenizer;

public class Customer {
	static String name ;
	String d;
	String m;
	static String y;
	void read() {
		Scanner Sc = new Scanner(System.in);
		System.out.println("\nEnter Name and DOB in Name/DD/MM/YYYY Format ");
		String str =Sc.next(); 
		StringTokenizer st = new StringTokenizer(str,","+"/");
			name=st.nextToken();
			d=st.nextToken();
			m=st.nextToken();
			y=st.nextToken();
			name=name.trim();
			d=d.trim();
			m=m.trim();
			y=y.trim();
				
		Sc.close();
	}
	void display() {
		System.out.println("\nCustomer Details is ");
		System.out.println(name+","+d+","+m+","+y);
	}						
	public static void main(String[] args) {
		Customer c1 = new Customer();
		c1.read();
		c1.display();
		
	}


}
