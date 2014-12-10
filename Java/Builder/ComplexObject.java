
public class ComplexObject {
	private int value;
	private int numberOfStuff;
	private String definition;
	public ComplexObject() {
		// TODO Auto-generated constructor stub
	}
	
	public void print()
	{
		System.out.println("Comples object: " + this.getDefinition() + " $"+ this.getValue() + " has a total of " + this.getNumberOfStuff());
	}
	
	public int getValue() {
		return value;
	}
	public void setValue(int value) {
		this.value = value;
	}
	public String getDefinition() {
		return definition;
	}
	public void setDefinition(String definition) {
		this.definition = definition;
	}
	public int getNumberOfStuff() {
		return numberOfStuff;
	}
	public void setNumberOfStuff(int numberOfStuff) {
		this.numberOfStuff = numberOfStuff;
	}

}
