/*
Given an array of integers, 
return a new array such that each element at index i of the new array is the
product of all the numbers in the original array except the one at i

For example, if our input was [1, 2, 3, 4, 5], the expected output would be
[120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would
be [2, 3, 6].

Follow-up: what if you can't use division?
*/

#include <array>
#include <iostream>
#include <iterator>
#include <algorithm>

template<std::size_t SIZE>
std::array<int, SIZE>
arrayProduct(std::array<int, SIZE>& arr)
{
    // get the product of the array
    int prod = 1;
    for (int i: arr)
    {
        prod *= i;
    }

    std::array<int, SIZE> temp;

    // divide each element by that element
    for (int i = 0; i < arr.size(); ++i)
    {
        temp[i] = prod / arr[i];
    }

    return temp;
}

void print(const int &i)
{
    std::cout << i << "\n";
}

int main()
{
    std::array<int, 3> myArray = {3, 2, 1};
    std::array<int, 3> outArray = arrayProduct(myArray);
    std::for_each(
        outArray.begin(),
        outArray.end(),
        print);
    
}
