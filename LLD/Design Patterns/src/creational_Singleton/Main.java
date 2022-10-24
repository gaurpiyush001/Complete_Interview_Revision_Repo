package creational_Singleton;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Singleton singleton = Singleton.getInstance();
		singleton.sayHello();
		
		Singleton singleton2 = Singleton.getInstance();
		singleton2.sayHello();
		
		//now if both Objects are at same Memory Address then
		//Singleton Class is working Correct

	}

}
