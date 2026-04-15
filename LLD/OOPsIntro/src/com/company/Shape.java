package com.company;

public abstract class Shape {
	
	String color;
	
	public Shape() {
		this.color = "RED";
		System.out.println("Your color is" + " " + this.color);
	}
	
	public abstract int area();
}

class Square extends Shape {
	
	int side;
	
	public Square() {
		super();
		System.out.println("Inside Square Constructor!");
		side = 4;
	}
	
	@Override //Ye readability aur error handling ke liye bhot bhadiya hai
	public int area() {
		return side*side;
	}
	
	
}




