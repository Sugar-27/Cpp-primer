#include <iostream>

int sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n = 0;
    std::cout << "Enter a number:" << std::endl;
    std::cin >> n;
    int eval = sum(n);
    std::cout << "Sum of 1 to the number inclusive is: " << eval << std::endl;
    return 0;
}