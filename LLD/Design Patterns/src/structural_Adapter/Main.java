package structural_Adapter;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Main Phil;osophy of Adapter Design Pattern ca be understand by RoundPeg and Hole Problem
		//In this we are having a RoundCircle shaped Obj of type RoundPeg and a hole with given radius, we need to figure out 
		//whether the RoundPeg will go inside the Hole or not
		
		
		// Simliarly problem arises when they are in-compatible type such that instead of RoundPeg there is SquarePeg, so 
		//we need to convert the SquarePeg Interface(called the Adaptee) to the RoundPeg Type(the Target Class) via a ADAPTER
		
		Hole hole = new Hole(10);
		RoundPeg roundObj = new RoundPeg(5);
		
		System.out.println("roundObj parsing in hole is " + hole.fit(roundObj));
		
		SquarePeg sqrObj = new SquarePeg(10);
		SquarePeg sqrObject = new SquarePeg(100);
		
		
		
		//Error (Incompatible Types)--> hole.fit(sqrObj);
		
		RoundPeg sqrObj1 = new SquarePegAdapter(sqrObj);
		RoundPeg sqrObj2 = new SquarePegAdapter(sqrObject);
		System.out.println(sqrObj2.getRadius());
		
		System.out.println("sqrObj1 parsing in hole is " + hole.fit(sqrObj1));
		System.out.println("sqrObj2 parsing in hole is " + hole.fit(sqrObj2));
		
		
	}

}
