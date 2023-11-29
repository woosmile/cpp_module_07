#include "iter.hpp"
#include <iostream>

void	integer_iter(int &num)
{
	num = num + 1;
}

void	char_iter(char &letter)
{
	letter = letter + 1;
}

int main(void)
{
	int		integer_array[10];
	char	char_array[10];

	std::cout << "iter before : integer array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		integer_array[i] = i;
		std::cout << integer_array[i] << " ";
	}

	std::cout << std::endl << "iter before : char array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		char_array[i] = 97 + i;
		std::cout << char_array[i] << " ";
	}

	std::cout << std::endl;

	::iter(integer_array, 10, integer_iter);
	::iter(char_array, 10, char_iter);

	std::cout << std::endl << "iter after(normal function) : integer array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << integer_array[i] << " ";
	}

	std::cout << std::endl << "iter after(normal function) : char array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << char_array[i] << " ";
	}

	std::cout << std::endl;

	::iter(integer_array, 10, ::iter_add_template<int>);
	::iter(char_array, 10, ::iter_add_template<char>);

	std::cout << std::endl << "iter after(instantiated function template) : integer array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << integer_array[i] << " ";
	}

	std::cout << std::endl << "iter after(instantiated function template) : char array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << char_array[i] << " ";
	}
	std::cout << std::endl;
	
	std::cout << std::endl << "test const parameter in function." << std::endl;

	::iter(integer_array, 10, ::iter_print_template<int>);
	::iter(char_array, 10, ::iter_print_template<char>);

	return (0);
}