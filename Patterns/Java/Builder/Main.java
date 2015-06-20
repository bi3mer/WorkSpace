
public class Main {
	public static void main(String[] args) 
	{
		System.out.println("Implementation of Builder class");
		Director director = new Director(new GlassBuilder());
		director.construct();
		ComplexObject obj = director.getProduct();
		obj.print();
	}

}
