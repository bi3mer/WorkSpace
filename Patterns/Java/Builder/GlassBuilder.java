
public class GlassBuilder implements Builder{
	
	private ComplexObject complexObject;
	
	public GlassBuilder() {
		this.complexObject = new ComplexObject();
	}

	@Override
	public void buildNumber() 
	{
		this.complexObject.setNumberOfStuff(20);
	}

	@Override
	public void buildValue() {
		this.complexObject.setValue(200);
	}

	@Override
	public void buildDefinition() {
		this.complexObject.setDefinition("This a builder for glass that is way over priced");
	}

	@Override
	public ComplexObject getObject() {
		return this.complexObject;
	}

}
