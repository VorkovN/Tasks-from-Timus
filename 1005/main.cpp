#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>

inline int rec(const std::vector<int> &nums, const int all_sum, int sum, int id)
{
    int dif = 0;

    //строим двоичное дерево
    if (id + 1 < nums.size()) {
        int dif1 = rec(nums, all_sum, sum + nums[id+1], id + 1);
        int dif2 = rec(nums, all_sum, sum, id + 1);
        //выбираем наименьшую разницу и оставляем ее
        dif = dif1 < dif2? dif1: dif2;
    }
    //возвращаем разность в кучках для одного из 2^n случаев
    else
        return abs(sum*2 - all_sum);
    return dif;

}

int main()
{

    int n;
    std::cin >> n;
    std::vector<int> nums;
    //создаем массив
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        nums.push_back(num);
    }
    //подсчет суммы
    const int sum = std::accumulate(nums.begin(), nums.end(), 0);

    //подсчет разницы
    std::cout << rec(nums, sum, 0, 0);

    return 0;
}