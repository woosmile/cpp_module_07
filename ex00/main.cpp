#include "whatever.hpp"
#include <iostream>

int main(void)
{
	int a = 2;
	int b = 3;
	
	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	double num1 = 42.42;
	double num2 = 42.42;

	std::cout << "num1 = " << &num1 << ", num2 = " << &num2 << std::endl;
	std::cout << "min( num1, num2 ) = " << &::min( num1, num2 ) << std::endl;
	std::cout << "max( num1, num2 ) = " << &::max( num1, num2 ) << std::endl;

	return (0);
}