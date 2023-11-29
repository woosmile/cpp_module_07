#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private:
		T				*_array_ptr;
		unsigned int	_len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		~Array();
		Array<T>&	operator=(const Array<T> &other);
	public:
		unsigned int size() const;
		T& operator[](long idx) const;
	public:
		class InvalidIndex: public std::exception
		{
			public:
				InvalidIndex();
				InvalidIndex(const InvalidIndex &other);
				~InvalidIndex() throw();
				InvalidIndex&	operator=(const InvalidIndex &other);
				const char*	what() const throw();
		};
};

# include "Array.tpp"

#endif