#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ofstream fout("lostcow.out");
    ifstream fin("lostcow.in");
    int x, y;
    fin >> x >> y;

    int pos = x;
    int dir = 1;
    int step = 1;
    int total = 0;
    while (true) {
        int next = x + dir * step;
        if ((pos <= y && y <= next) || (pos >= y && y >= next)) {
            total += abs(y - pos);
            break;
        } else {
            total += abs(next - pos);
        }
        pos = next;
        dir *= -1;
        step *= 2;
    }
    fout << total << endl;
    return 0;
}