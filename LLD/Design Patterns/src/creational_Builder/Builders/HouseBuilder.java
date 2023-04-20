package creational_Builder.Builders;

import creational_Builder.Product.House;

public interface HouseBuilder {
	
	//steps before creation of Object
	public void buildBasement();
	public void buildStructure();
	public void buildRoof();
	public void buildInterior();
	
	//final creation of Object
	public House getHouse();

}
