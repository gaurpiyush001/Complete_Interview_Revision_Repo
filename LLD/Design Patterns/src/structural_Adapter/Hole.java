package structural_Adapter;
//This is the Hole, inside which we Object to be parsed, with Hole,radius >= Obj.radius
public class Hole {
	
	public int radius;
	
	public Hole() {
		
	}
	
	public Hole(int radius) {
		this.radius = radius;
	}
	
	public boolean fit(RoundPeg Obj) {
		return this.radius >= Obj.getRadius();
	}

}
