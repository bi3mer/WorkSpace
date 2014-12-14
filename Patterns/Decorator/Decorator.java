
abstract class Decorator implements Component{
	protected Component component;
	
	public Decorator(Component comp) {
		this.component = comp;
	}

	public void printStuff() {
		this.component.printStuff();
	}

}
