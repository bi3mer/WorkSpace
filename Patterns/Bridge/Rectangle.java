
public class Rectangle extends Shape {

	public Rectangle(Color c) {
		super(c);
	}

	@Override
	public void printShape() {
		System.out.println("this is a " + this.color.applyColor() + " rectangle");
	}

}
