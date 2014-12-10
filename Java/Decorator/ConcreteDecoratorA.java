
public class ConcreteDecoratorA extends Decorator{

	public ConcreteDecoratorA(Component comp) {
		super(comp);
	}
	@Override
	public void printStuff()
	{
		this.component.printStuff();
		System.out.println("I'm concrete decorator A!");
	}
}
