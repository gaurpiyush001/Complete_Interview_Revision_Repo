package structural_Adapter;

//Our Adapter =====> SquarePegAdapter

//Note***** Our Adapter Class Always extends the TARGET CLASS

public class SquarePegAdapter extends RoundPeg {
	
	private SquarePeg Obj;
	
	public SquarePegAdapter() {}
	
	public SquarePegAdapter(SquarePeg s) {
		this.Obj = s;
	}
	
	public double getRadius() {
		return this.Obj.getWidth() * Math.sqrt(2) / 2;
	}

}
