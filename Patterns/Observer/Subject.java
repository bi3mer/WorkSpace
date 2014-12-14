import java.util.Observable;





public class Subject extends Observable{
	public Subject() {
		
	}
	public void setChanged()
	{
		super.setChanged(); // access protected method
	}

}
