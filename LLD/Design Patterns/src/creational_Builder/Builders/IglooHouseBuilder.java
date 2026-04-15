package creational_Builder.Builders;

import creational_Builder.Product.House;

public class IglooHouseBuilder implements HouseBuilder {

	private House house;
	
	public IglooHouseBuilder() {
		this.house = new House();
	}
	
	@Override
	public void buildBasement() {
		// TODO Auto-generated method stub
		house.setBasement("Ice Bars");
		
	}

	@Override
	public void buildStructure() {
		// TODO Auto-generated method stub
		house.setStructure("Ice Blocks");
	}

	@Override
	public void buildRoof() {
		// TODO Auto-generated method stub
		house.setRoof("Ice Dom");
	}

	@Override
	public void buildInterior() {
		// TODO Auto-generated method stub
		house.setInterior("Ice Carvings");
	}

	@Override
	public House getHouse() {
		// TODO Auto-generated method stub
		return this.house;
	}
	
	

}
