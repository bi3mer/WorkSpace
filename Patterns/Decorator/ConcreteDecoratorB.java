
public class ConcreteDecoratorB extends Decorator{

	public ConcreteDecoratorB(Component comp) {
		super(comp);
	}
	
	public void printStuff()
	{
		this.component.printStuff();
		System.out.println("I'm concrete decorator b!");
	}
}
