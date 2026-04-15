package creational_Factory_Method;

public class DomesticPlan extends Plan{
	
	@Override
	public void getRate() {
		this.rate = 3;
		System.out.println("rate updated to " + this.rate);		
	}

}
