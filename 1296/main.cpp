#include <iostream>

int main()
{
    int n, num, sum = 0, res = 0;

    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> num;
        if (res < sum) res = sum;
        sum = num + sum < 0? 0: num + sum;
    }
    if (res < sum) res = sum; //на случай если нужно учесть последнее число

    std::cout << (res > 0? res:0);

    return 0;
}

