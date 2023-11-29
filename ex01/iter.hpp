#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T1, typename T2, typename T3>
void iter(T1 addr, T2 len, T3 f)
{
	T2	i = 0;

	while (i < len)
	{
		f(addr[i]);
		i++;
	}
}

template <typename T1>
void iter_add_template(T1 &val)
{
	val = val + 1;
}

template <typename T1>
void iter_print_template(T1 const &val)
{
	std::cout << val << std::endl;
}

#endif