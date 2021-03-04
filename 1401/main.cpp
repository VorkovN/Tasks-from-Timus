#include <iostream>
#include <vector>
#include <cmath>

void print(const std::vector<std::vector<int>> &field)
{
    for (const std::vector<int> &v: field) {
        for (int i: v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//ix1 - левый, iy1 - правый
void paint_2x2(int color, const int x, const int y, const int ix, const int iy, std::vector<std::vector<int>> &field)
{
    int s = 1;
    int b = std::pow(2, s);//2
    int a = b / 2;//1

    if (y % b < a && x % b < a) {
        field[iy + a - 1][ix + a] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
    }
    if (y % b < a && x % b > a - 1) {
        field[iy + a - 1][ix + a - 1] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
    }
    if (y % b > a - 1 && x % b < a) {
        field[iy + a - 1][ix + a] = color;
        field[iy + a - 1][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
    }
    if (y % b > a - 1 && x % b > a - 1) {
        field[iy + a - 1][ix + a] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a - 1][ix + a - 1] = color;
    }
}

void paint_4x4(int &color, const int x, const int y, const int ix, const int iy, std::vector<std::vector<int>> &field)
{
    int s = 2;
    int b = std::pow(2, s);
    int a = b / 2;
    if (y % b < a && x % b < a) {
        paint_2x2(++color, x, y, ix, iy, field);
        ++color;
        field[iy + a - 1][ix + a] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
        paint_2x2(++color, ix + a, iy + a - 1, ix + a, iy, field);
        paint_2x2(++color, ix + a - 1, iy + a, ix, iy + a, field);
        paint_2x2(++color, ix + a, iy + a, ix + a, iy + a, field);

    }

    if (y % b < a && x % b > a - 1) {
        paint_2x2(++color, x, y, ix + a, iy, field);
        ++color;
        field[iy + a - 1][ix + a - 1] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
        paint_2x2(++color, ix + a - 1, iy + a - 1, ix, iy, field);
        paint_2x2(++color, ix + a - 1, iy + a, ix, iy + a, field);
        paint_2x2(++color, ix + a, iy + a, ix + a, iy + a, field);

    }

    if (y % b > a - 1 && x % b < a) {
        paint_2x2(++color, x, y, ix, iy + a, field);
        ++color;
        field[iy + a - 1][ix + a] = color;
        field[iy + a - 1][ix + a - 1] = color;
        field[iy + a][ix + a] = color;
        paint_2x2(++color, ix + a, iy + a - 1, ix + a, iy, field);
        paint_2x2(++color, ix + a - 1, iy + a - 1, ix, iy, field);
        paint_2x2(++color, ix + a, iy + a, ix + a, iy + a, field);

    }

    if (y % b > a - 1 && x % b > a - 1) {
        paint_2x2(++color, x, y, ix + a, iy + a, field);
        ++color;
        field[iy + a - 1][ix + a] = color;
        field[iy + a][ix + a - 1] = color;
        field[iy + a - 1][ix + a - 1] = color;
        paint_2x2(++color, ix + a, iy + a - 1, ix + a, iy, field);
        paint_2x2(++color, ix + a - 1, iy + a, ix, iy + a, field);
        paint_2x2(++color, ix + a - 1, iy + a - 1, ix, iy, field);

    }
}

int main()
{
    int color = 0;
    int n, x, y;
    std::cin >> n >> x >> y;
    --x;
    --y;
    std::vector<std::vector<int>> field(std::pow(2, n), std::vector<int>(std::pow(2, n), 0));

    paint_4x4(color, x, y, 0, 0, field);
    print(field);

    return 0;
}
