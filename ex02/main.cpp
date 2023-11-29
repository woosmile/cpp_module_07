#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10

void    leak_check(void)
{
    std::system("leaks a.out");
}

template <typename T1, typename T2>
void    print_value(T1 &val1, T2 &val2)
{
    std::cout << "Array<int>" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "[" << i << "] : " << val1[i] << std::endl;
    }

    std::cout << "Mirror" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "[" << i << "] : " << val2[i] << std::endl;
    }
}

int main(void)
{
    atexit(leak_check);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    std::cout << "initial value" << std::endl;
    print_value(numbers, mirror);
    std::cout << "numbers length : " << numbers.size() << std::endl;

    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 10;
        mirror[i] = rand() % 10;
    }

    std::cout << "random value" << std::endl;
    print_value(numbers, mirror);

    {
        std::cout << "copy constructor test" << std::endl;
        Array<int> copy_test(numbers);
        print_value(numbers, copy_test);
        std::cout << "Change copy_test value" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            copy_test[i] = rand() % 10;
        }
        print_value(numbers, copy_test);
    }

    {
        std::cout << "copy assignment operator test" << std::endl;
        Array<int> copy_assign_test;
        copy_assign_test = numbers;
        print_value(numbers, copy_assign_test);
        std::cout << "Change copy_assign_test value" << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            copy_assign_test[i] = rand() % 10;
        }
        print_value(numbers, copy_assign_test);
    }

    try
    {
        std::cout << numbers[10] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    Array<int> default_constructor;
    delete[] mirror;
    return (0);
}