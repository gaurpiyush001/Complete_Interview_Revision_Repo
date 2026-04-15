package creational_Singleton;

public class Singleton {
	
	//iska kya fayeda??
	//bhaiyaJi this static member serves as a flag which tells
	//whether an Object has already been created or No Object is created till now  
	static Singleton instance = null;
	
	//Why PRIVATE CONSTRUCTOR??
	//Because we do not want any user from outside the class to create an object 
	//by calling Constructor function 
	private Singleton() {
		
	}
	
	static Singleton getInstance() {
		if(instance == null) {
			instance = new Singleton();
		}
		return instance;
	}
	
	public void sayHello() {
		System.out.println("Hi, I am a Singleton Class");
		System.out.println(instance);
	}

}
