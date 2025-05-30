#include <fstream>

using namespace std;

int main() {
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    int b_bronze, a_bronze, b_silver, a_silver, b_gold, a_gold, b_plat, a_plat;

    fin >> b_bronze >> a_bronze;
    fin >> b_silver >> a_silver;
    fin >> b_gold >> a_gold;
    fin >> b_plat >> a_plat;

    int prom_plat = a_plat - b_plat;
    int prom_gold = (a_gold - b_gold) + prom_plat;
    int prom_silver = (a_silver - b_silver) + prom_gold;

    fout << prom_silver << endl;
    fout << prom_gold << endl;
    fout << prom_plat << endl;

    return 0;
}