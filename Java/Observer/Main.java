
public class Main {
	public static void main(String[] args) 
	{
		System.out.println("this implements the Observer pattern");
		Subject subject = new Subject();
		ConcreteObserver colan = new ConcreteObserver("Colan");
		ConcreteObserver jim = new ConcreteObserver("jim");
		ConcreteObserver phil = new ConcreteObserver("phil");
		ConcreteObserver van = new ConcreteObserver("van");
		subject.addObserver(colan);
		subject.addObserver(jim);
		subject.addObserver(phil);
		subject.addObserver(van);
		subject.setChanged(); // so we can run notifyObservers
		subject.notifyObservers("Colan");
	}

}
