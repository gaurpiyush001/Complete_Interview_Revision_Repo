package creational_Builder.Director;

import creational_Builder.Builders.HouseBuilder;
import creational_Builder.Product.House;

//Civil Engineer has houseBuilder, and houseBuilder builds the house

public class CivilEngineer {
	
	private HouseBuilder houseBuilder;
	
	//Konsey type ka houseBuilder hai
	public CivilEngineer(HouseBuilder houseBuilder) {
		this.houseBuilder = houseBuilder;
	} 
	
	public House getHouse() {
		return this.houseBuilder.getHouse();
	}
	
	public void constructHouse() {
		
		this.houseBuilder.buildBasement();
		this.houseBuilder.buildStructure();
		this.houseBuilder.buildRoof();
		this.houseBuilder.buildInterior();
		
	}

}
