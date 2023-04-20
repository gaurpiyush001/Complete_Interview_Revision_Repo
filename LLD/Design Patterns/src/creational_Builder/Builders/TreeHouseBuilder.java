package creational_Builder.Builders;

import creational_Builder.Product.House;

public class TreeHouseBuilder implements HouseBuilder {

	private House house;
	
	public TreeHouseBuilder() {
		this.house = new House();
	}
	
	
	@Override
	public void buildBasement() {
		// TODO Auto-generated method stub
		house.setBasement("Ice Tree Bars");
		
	}

	@Override
	public void buildStructure() {
		// TODO Auto-generated method stub
		house.setStructure("Ice Tree Blocks");
	}

	@Override
	public void buildRoof() {
		// TODO Auto-generated method stub
		house.setRoof("Ice Tree Dom");
	}

	@Override
	public void buildInterior() {
		// TODO Auto-generated method stub
		house.setInterior("Ice Tree Carvings");
	}

	@Override
	public House getHouse() {
		// TODO Auto-generated method stub
		return this.house;
	}

}
