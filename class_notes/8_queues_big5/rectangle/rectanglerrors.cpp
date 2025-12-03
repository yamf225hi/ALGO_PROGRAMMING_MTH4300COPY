#include "rectangle.h"
#ifndef RECTANGLE_H 
#define RECTANGLE_H

class Rectangle { 
public:
	Rectangle(double width, double height); // Constructor 
	double getPerimeter() const; // Member function to get perimeter 
	void setHeight(double height) const;// Sets height
	void getHeight();          // Gets height

private:
	double width;// Member variables double height;
	
	};

#endif // RECTANGLE_H

**rectangle.cpp:**

#include<iostream>

#include "rectangle.h"

// Constructor definition

Rectangle::Rectangle(double width, double height) 
	: width(width), height(height) {}

// Function to calculate the area of the rectangle 

double Rectangle::getArea() const
{ 
	return width * height;

}

// Sets height

double Rectangle::getPerimeter() const

{ 
	return 2 * (width + height);

}

// Function to calculate the perimeter of the rectangle

double Rectangle::setHeight(double h) const

{ height=h;

}

// Gets height

void getHeight()

{ return height;

}

**main.cpp:** 
#include <iostream>

int main()

{
	Rectangle rect(10.0, 5.0); // Create a Rectangle object with width 5.0 and height 3.0 
	std::cout << "Area: " << rect.getArea() << std::endl; std::cout << "Perimeter: " << rect.getPerimeter() << std::endl; std::cout <<rect<< std::endl; 

	return 0;

}