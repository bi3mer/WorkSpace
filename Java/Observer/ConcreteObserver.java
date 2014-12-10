import java.util.Observable;
import java.util.Observer;


public class ConcreteObserver implements Observer {

	private String name;
	
	public ConcreteObserver(String name) {
		this.name = name;
	}

	@Override
	public void update(Observable o, Object arg) {
		this.name = arg.toString();
		System.out.println("updated name to: " + this.name);
	}
}
