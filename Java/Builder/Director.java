
public class Director 
{
	private Builder builder;
	
	public Director(Builder builder) {
		this.builder = builder;
	}
	
	public void construct()
	{
		this.builder.buildDefinition();
		this.builder.buildNumber();
		this.builder.buildValue();
	}
	
	public ComplexObject getProduct()
	{
		return this.builder.getObject();
	}
}
