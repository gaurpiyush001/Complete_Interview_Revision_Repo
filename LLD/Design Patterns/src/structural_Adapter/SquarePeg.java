package structural_Adapter;

//This is the Adaptee Class, which we need to convert to RoundPeg to test against whole radius

//So we will be using Adapter to comvert the InCompatible Interfaces to Compatible

public class SquarePeg {
	
	private int width;
	
	public SquarePeg() {}
	
	public SquarePeg(int width) {
		this.width = width;
	}
	
	public double getWidth() {
		return this.width;
	}

}
