
#include "stdafx.h"
#include "Power.h"
#include <assert.h>
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>

bool isEven(const int number)
{
	return (number % 2 == 0);
}
bool isOdd(const int number)
{
	return (!isEven(number));
}
void printBaseCaseInformation()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "\n\n  ORDER of return values";
	std::this_thread::sleep_for(std::chrono::milliseconds(666));
	std::cout << "\n\n  (IMPORTANT NOTE: RETURN will propogate UP the order of CALLS, starting at the BASE case)";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}
void printRecursiveInformation(const int base, const int exponent)
{
	if (exponent == 0)
	{
		std::cout << "\n\n\nBase case: power(" << base << ", " << exponent <<
			") --> (" << base << "^0 = 1)"
			<< "\n return =  1";
	}
	else if (exponent == 1)
	{
		std::cout << "\n\n\nBase case: power(" << base << ", " << exponent <<
			") --> (" << base << "^1 = " << base << ")";
	}
	else 
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cout << "\n\nNext return: power(" << base << ", " << exponent <<
			") --> ";
			
		if (isEven(exponent))
		{
			std::cout << " (" << base << "^"
				<< exponent << " = " << base << "^" << exponent / 2 << " * " <<
				base << "^" << exponent / 2
				<< ") -->\n return " <<
				"power(" << base << ", " << exponent / 2 << ") * "
				"power(" << base << ", " << exponent / 2 << ")"
				<< std::endl;
			std::cout << " (Refer to LAST return value) \n return = " << static_cast<int>(std::pow(base, exponent / 2)) <<
				" * " << static_cast<int>(std::pow(base, exponent / 2));
		}
		else if (isOdd(exponent))
		{
			std::cout << " (" << base << "^"
				<< exponent << " = " << base << "^" << exponent / 2 << " * " <<
				base << "^" << exponent / 2
				<< " * " << base << "^1) -->\n return " <<
				"power(" << base << ", " << exponent / 2 << ") * "
				"power(" << base << ", " << exponent / 2 << ") * "
				<< base << std::endl;
			std::cout << " (Refer to LAST return value) \n return = " << static_cast<int>(std::pow(base, exponent / 2)) <<
				" * " << static_cast<int>(std::pow(base, exponent / 2)) <<
				" * " << base;
		}
	}
}
void printReturn(const int returnValue)
{
	std::cout << "  \n return = " << returnValue << std::endl;
}

/*
Note: Text is indented away to get to the meat of the function
precondition: 
	exponent >= 0
postcondition:
	returns the result of the base raised to the exponent
	(e.g. power(2, 2) = 4)
*/
int power(int base, int exponent)
{
	assert(exponent >= 0);

			std::this_thread::sleep_for(std::chrono::milliseconds(666));
			std::cout << "\npower(" << base << ", " << exponent << ")" << std::endl;

	if (exponent == 0)
	{
			printBaseCaseInformation();
			printRecursiveInformation(base, exponent);
			printReturn(1);
		return 1;
	}
	else if (exponent == 1)
	{
			printBaseCaseInformation();
			printRecursiveInformation(base, exponent);
			printReturn(base);
		return base;
	}

	int halfOfProducts = power(base, exponent / 2);

	if ( isEven(exponent) )
	{
			printRecursiveInformation(base, exponent);
		int result = halfOfProducts * halfOfProducts;
			printReturn(result);
		return result;
	}

	else 
	{
			printRecursiveInformation(base, exponent);
		int result = halfOfProducts * halfOfProducts * base;
			printReturn(result);
		return result;
	}
}