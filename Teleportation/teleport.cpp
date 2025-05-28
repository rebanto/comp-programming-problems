#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

int walking_dist_tp(int closest, int farthest, int a, int b) {
    int walking_dist = 0;

    walking_dist += abs(closest - a);
    walking_dist += abs(b-farthest);

    return walking_dist;
}

int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, x, y;
    fin >> a >> b >> x >> y;
    
    int distances[2];

    int closest_tp, farthest_tp;
    int to_walk = abs(b - a);

    distances[0] = to_walk;

    if (abs(a-x) > abs(a-y)) {
        closest_tp = y;
        farthest_tp = x;
    } else  {
        closest_tp = x;
        farthest_tp = y;
    }
    
    distances[1] = walking_dist_tp(closest_tp, farthest_tp, a, b);

    cout << distances[0] << " " << distances[1] << endl;
    fout << min(distances[0], distances[1]);
}