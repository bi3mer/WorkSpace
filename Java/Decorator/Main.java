
public class Main {
	public static void main(String[] args) 
	{
		Component comp = new ConcreteDecoratorB(new ConcreteDecoratorA(new ConcreteDecoratorA(new ConcreteClass())));
		comp.printStuff();
	}

}
