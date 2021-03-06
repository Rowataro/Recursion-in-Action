//Purpose:
//Good visualization of recursive functions and how they work
//Interactive as one can set different bases and exponents.

#include "stdafx.h"

//For FUTURE REFERENCE: 
// When precompiled headers are enabled, the compiler will ignore the contents of all includes
// that occur PRIOR to the inclusion of #include "stdafx.h" 
// Therefore include all user header files AFTER to avoid any compilation errors
// of not being able to find functions in Power.h

#include "Power.h"
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

void printIntro();
void setExample(int &base, int &exponent);
void printFunctionInformation(const int base, const int exponent);
void askToExit(int& choice);

int main()
{
	printIntro();

	int base;
	int exponent;
	
	int choice;
	int sentinel = -1;
	do
	{
		setExample(base, exponent);
		printFunctionInformation(base, exponent);
		
		int number = power(base, exponent);
		assert(number == static_cast<int>(std::pow(base, exponent)));
		std::cout << "\nSuccessful exponentiation!" << std::endl;

		askToExit(choice);
	} while (choice != sentinel);

	std::cout << "\n\nYou have exited the program." << std::endl;

    return 0;
}

void printIntro()
{
	std::cout << "This program implements exponentiation with recursion." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(666));
	std::cout << "Look inside the code to see exact details." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(666));
	std::cout << "See a recursive functions in action!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(666));
}

void setExample(int &base, int &exponent)
{
	std::cout << "\n\nFunction signature -- int power(int base, int exponent) ";
	std::cout << "\nbase: ";
	std::cin >> base;
	
	std::cout << "\nExponent must be non-negative (>=0).";
	int input;
	do
	{
		std::cout << "\nExponent: ";
		std::cin >> input;

		if (input < 0)
		{
			std::cout << "\nInvalid input.";
			std::cin.clear(); //clear bad input flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		}

	} while (input < 0 );
	exponent = input;
}
void printFunctionInformation(const int base, const int exponent)
{
	std::cout << "\n\nInitial call:" <<
		"\nbase = " << base << "   exponent = " << exponent << std::endl;

	if (exponent != 0 && exponent != 1)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "\n  ORDER of calls ";
		
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "\n  ( power(int base, int exponent) will call itself multiple times, by definition of RECURSION.)" << std::endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

void askToExit(int &choice)
{
	std::cout << "\nDo you want to exit?";
	std::cout << "\nEnter Yes (-1)  or   No (Other integer): ";
	std::cin >> choice;
}