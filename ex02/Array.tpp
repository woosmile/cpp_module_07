#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array(): _len(0)
{
	std::cout << "default constructor called" << std::endl;
	_array_ptr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): _len(n)
{
	std::cout << "default constructor with parameter called" << std::endl;
	_array_ptr = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	std::cout << "copy constructor called" << std::endl;
	if (this != &other)
	{
		_len = other._len;
		_array_ptr = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
		{
			_array_ptr[i] = other[i];
		}
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array_ptr;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T> &other)
{
	std::cout << "copy assignment operator called" << std::endl;
	if (this != &other)
	{
		delete[] _array_ptr;
		_len = other._len;
		_array_ptr = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
		{
			_array_ptr[i] = other[i];
		}		
	}
	return (*this);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_len);
}

template <typename T>
T& Array<T>::operator[](long idx) const
{
	if (idx < 0 || idx >= _len)
		throw (Array<T>::InvalidIndex());
	return (_array_ptr[idx]);
}

template <typename T>
const char*	Array<T>::InvalidIndex::what() const throw()
{
	return ("Invalid index.");
}

template <typename T>
Array<T>::InvalidIndex::InvalidIndex()
{
}

template <typename T>
Array<T>::InvalidIndex::InvalidIndex(const Array<T>::InvalidIndex &other)
{
	(void)other;
}

template <typename T>
Array<T>::InvalidIndex::~InvalidIndex() throw()
{
}

template <typename T>
typename Array<T>::InvalidIndex &Array<T>::InvalidIndex::operator=(const Array<T>::InvalidIndex &other)
{
	(void)other;
	return (*this);
}


#endif