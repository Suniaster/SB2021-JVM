/*
 * Compile assim: javac short_cast.java -target 1.2 -source 1.2
 */
public class short_cast{
	public static void main(String args[]){
		int a=0xFF;
		/*l2d*/
		long b= a;
		/*l2f*/
		float c=(float)a;
		/*l2i*/
		int d=(int)a;
		double e = (double)a;
		int f = (int)b;
		
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		System.out.println(d);
		System.out.println(e);
		System.out.println(f);
		
		// b=(double)a;
		/*l2f*/
		c=(float)a;
		/*l2i*/
		d=(int)a;
		
		System.out.println(a);
		System.out.println(b);
		System.out.println(c);
		System.out.println(d);
	}	
}