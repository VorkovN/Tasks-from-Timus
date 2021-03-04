#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int fighters;
        int teams;
        std::cin >> fighters >> teams;
        int min_team_size = fighters / teams;
        //кол-во команд с численностью min_team_size + 1
        int ost = fighters % teams;
        //перебор всех команд, j - кол-во еще не учтенных команд
        for (int j = teams - 1; j > 0; --j) {
            //суммирование для min_team_size бойцов в каждой команде
            sum += j * min_team_size * min_team_size;
            if (ost > 0)
            {
                //суммирование для неучтенных бойцов
                sum += (j - (ost - 1)) * min_team_size + (ost - 1) * (min_team_size + 1) + (ost - 1) * min_team_size;
                --ost;
            }
        }
        std::cout << sum << std::endl;
    }

    return 0;
}
