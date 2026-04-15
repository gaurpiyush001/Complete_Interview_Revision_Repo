package structural_Adapter;

//This is the Target Class, as Only Round Objects are allowed to test against hole radius

public class RoundPeg {
	
	public int radius;
	
	public RoundPeg() {}
	
	public RoundPeg(int radius) {
		this.radius = radius;
	}
	
	public double getRadius() {
		return this.radius;
	}

}
