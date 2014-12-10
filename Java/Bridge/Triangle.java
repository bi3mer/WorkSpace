
public class Triangle extends Shape{

	public Triangle(Color c) {
		super(c);
	}

	@Override
	public void printShape() {
		System.out.println("this is a " + this.color.applyColor() + " triangle");
	}

}
