package creational_Factory_Method;

abstract class Plan {
	
	protected double rate;
	
	abstract void getRate();
	
	public void calculateBill(int units) {
		System.out.println("Value of rate is " + this.rate);
		System.out.println("total bill is " + (units * rate));
	}

}
