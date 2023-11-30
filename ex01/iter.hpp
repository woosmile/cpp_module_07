#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2>
void iter(T1 addr, unsigned int len, T2 f)
{
	unsigned int	i = 0;

	while (i < len)
	{
		f(addr[i]);
		i++;
	}
}

template <typename T>
void iter_add_template(T &val)
{
	val = val + 1;
}

template <typename T>
void iter_print_template(T const &val)
{
	std::cout << val << std::endl;
}

#endif