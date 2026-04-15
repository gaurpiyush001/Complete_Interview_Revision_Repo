package pol;

public class classFirst {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
//		System.out.println("My name is Piyush");
		
		//Create an Object
		Human chitti = new Human();
		System.out.println("Returned from Constructor");
		chitti.age = 23;
		chitti.weight = 32;
		chitti.sleep();
		
		//Use case of Constructor --> values ko Initialize krna
		Human chit = new Human(14, 25);
		System.out.println(chit.age + " " + chit.weight);
		
		System.out.println("Number Of objects Created" + Human.count);
		
		Human alpha = new Male();
		alpha.sleep();
	}

}

class Human {
	
	//properties
	int age;
	int weight;
	
	//this is a property of a class, It can be accessed even after No Object is Instantiated from class
	static int count = 0;//it gives no. of Objects Created
	
	//Constructor(It is automatically called at the time of Object Creation) two types-:
//	(Java mein Copy Constructor nhi hota)
	
	//1.) No-arg Constructor
	 public Human() {//Default Constructor
		 this(23, 34);
		 count++;
		 //initializing
		 age = 0;
		 weight = 0; 
		 System.out.println("Inside the constructor - Creating Object");
	 }
		
	
	//2.) parameterized Constructor
	public Human(int age, int weight) {
		
		//constructor Invoke hojayega isse
		//this();//current Object ka constructor call krdo

		count++;
		this.age = age;
		this.weight = weight;
		
		System.out.println("inside parameterized constructor" + age + " " + weight);
	}
	
	//Constructor Overloading -> Same name with different list or type of parameters
	public Human(int age) {
		count++;
		this.age = age;
	}
	 
	//-> Do Constructor Return Any Value??
	/*
	Well, this is the most important and million-dollar question about the Java 
	constructors. However, constructors are the special type of methods defined with 
	the same name as the class. Like a method, the Constructor can also be overloaded.

	In general, the java constructor doesn't return any specific value, which can 
	directly affect the code because it is not like a normal method used in the java 
	code. Also, the fact that a constructor is not directly called by the java code 
	infect is called by the memory allocation and object initialization code at runtime.

	However, a method's work is to return the result to the caller, whereas the 
	Constructor is more responsible for assigning the initial values to the data members
	of the class. Although the Constructor can also contain the number of instructions 
	inside it, it can't return the result of statements.
	###Here, we should also notice that a constructor returns the instance created by
	the new keyword in our java code. 
	*/
	
	
	//behaviour
	void sleep() {
		System.out.println("Bhaiya is Sleeping");
	}
	
	static void update() {
		count++;
	}
	
}


class Male extends Human{
	
	
	
}
