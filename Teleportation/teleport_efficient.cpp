/*
Solution Notes:
- The problem asks for the minimum distance to travel from point a to b, possibly using a teleport between x and y.
- There are three possible ways:
    1. Walk directly from a to b: abs(b - a)
    2. Walk from a to x, teleport to y, then walk to b: abs(a - x) + abs(b - y)
    3. Walk from a to y, teleport to x, then walk to b: abs(a - y) + abs(b - x)
- The answer is the minimum of these three options.
- This approach is O(1) and covers all cases, including when teleporting is not helpful.
*/

#include <fstream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, x, y;
    fin >> a >> b >> x >> y;

    int direct = abs(b - a);
    int tp1 = abs(a - x) + abs(b - y);
    int tp2 = abs(a - y) + abs(b - x);

    int answer = min({direct, tp1, tp2});
    fout << answer << endl;
}