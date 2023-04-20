package creational_Builder;

import creational_Builder.Builders.HouseBuilder;
import creational_Builder.Builders.IglooHouseBuilder;
import creational_Builder.Director.CivilEngineer;
import creational_Builder.Product.House;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//we want to build HouseType: Igloo
		HouseBuilder iglooBuilder = new IglooHouseBuilder();
		
		//tell that to our Director i.e Civil Engineer
		CivilEngineer engineer = new CivilEngineer(iglooBuilder);
		
		//engineer starts constructing house
		engineer.constructHouse();
		
		//house creation done, just just fetch th house
		House house = engineer.getHouse();
		
		//Prints the house
		System.out.println("Builder constructor: "+ house);
		
		
	}

}
