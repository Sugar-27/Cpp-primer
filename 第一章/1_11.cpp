#include <iostream>

int sum(int n1, int n2)
{
    int sum = 0;
    for (int i = n1; i <= n2; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n1, n2 = 0;
    std::cout << "Enter two numbers:" << std::endl;
    std::cin >> n1 >> n2;
    int eval = sum(n1, n2);
    std::cout << "Sum of " << n1 << " to " << n2 << " inclusive is: " << eval << std::endl;
    return 0;
}