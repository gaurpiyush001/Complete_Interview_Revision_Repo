package creational_Factory_Method;

//let the Subclass decide which class to Instantiate
public class PlanFactory {
	
	
	//getPlan responsibility ->>
	//Instantiating a particular class on the basis of Business Logic or Condition 
	public Plan getPlan(String planName) {
		if(planName == null) {
			return null;
		}
		
		if(planName.equalsIgnoreCase("domestic")) {
			return new DomesticPlan();
		}
		else if(planName.equalsIgnoreCase("commercial")) {
			return new CommercialPlan();
		}
		
		else if(planName.equalsIgnoreCase("industrial")) {
			return new IndustrialPlan();
		}
		
		return null;
		
	}

}
