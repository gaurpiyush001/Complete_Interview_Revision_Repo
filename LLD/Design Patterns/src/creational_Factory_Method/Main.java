package creational_Factory_Method;

import java.util.Scanner;

//This is not a good code structure, as we have wrapped 
//everything abstract as well as concrete class in One Single Package
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//creating Factory Object
		PlanFactory factory = new PlanFactory();
		
		
		//take Input
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the name of the Plan.");
		String planName = sc.nextLine();  
		
		System.out.println("Enter the Number of Units.");
		
		int units = sc.nextInt();
		sc.close();
		
		Plan plan = factory.getPlan(planName);
		
		System.out.println("Plan name is : ");
		System.out.println(planName);
		
		System.out.println("Rate is : ");
		
		plan.getRate();
		plan.calculateBill(units);
		
		
	}

}
