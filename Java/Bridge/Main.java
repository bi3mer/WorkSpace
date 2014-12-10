
public class Main {
	public static void main(String[] args) {
		System.out.println("this ipmlements the bridge pattern");
		/*
		 * Going to implement a Shape class which uses the color class to applyColor()
		 */
		Shape triangle = new Triangle(new RedColor());
		Shape rectangle = new Rectangle(new RedColor());
		triangle.printShape();
		rectangle.printShape();
	}

}
