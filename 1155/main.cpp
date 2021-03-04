#include <iostream>
#include <vector>

//удаление максимального кол-во дуонов в соседних вершинах
void del(std::vector<int> &nums, int i1, int i2)
{
    while (std::min(nums[i1], nums[i2])) {
        std::cout << char(int('A') + i1) << char(int('A') + i2) << '-' << std::endl;
        --nums[i1];
        --nums[i2];
    }
}

//добавление dif дуонов в соседние вершины
void add(std::vector<int> &nums, int i1, int i2, int dif)
{
    for (int i = 0; i < dif; ++i) {
        std::cout << char(int('A') + i1) << char(int('A') + i2) << '+' << std::endl;
        ++nums[i1];
        ++nums[i2];
    }
}

int main()
{
    std::vector<int> nums(8);
    std::vector<int> kostyl_vector = {1, 2, 3, 7, 4, 5, 1};

    for (int i = 0; i < 8; ++i)
        std::cin >> nums[i];

    if (nums[0] + nums[2] + nums[5] + nums[7] != nums[1] + nums[3] + nums[4] + nums[6]) {
        std::cout << "IMPOSSIBLE";
        return 0;
    }

    //зануление вершины A
    del(nums, 0, 4);
    del(nums, 0, 3);
    del(nums, 0, 1);

    if (nums[0]) {
        add(nums, 4, 5, nums[0]);
        del(nums, 0, 4);
    }

    //зануление вершины G
    del(nums, 6, 5);
    del(nums, 6, 7);
    del(nums, 6, 2);

    if (nums[6]) {
        add(nums, 5, 4, nums[6]);
        del(nums, 6, 5);
    }

    //гоним дуоны по кругу B C D H E F
    for (int i = 0; i < 5; ++i) {
        del(nums, kostyl_vector[i], kostyl_vector[i+1]);
        if (nums[kostyl_vector[i]]) {
            add(nums, kostyl_vector[i + 1], kostyl_vector[i+2], nums[kostyl_vector[i]]);
            del(nums, kostyl_vector[i], kostyl_vector[i+1]);
        }
    }



    return 0;
}