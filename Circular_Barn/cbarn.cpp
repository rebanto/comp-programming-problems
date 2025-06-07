#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_distance_from_start(vector<int>& r) {
    int counter = 0, d = 0;

    for (int cows : r) {
        d += counter * cows;
        counter++;
    }

    return d;
}

int main() {
    ofstream fout("cbarn.out");
    ifstream fin("cbarn.in");
    int n, tmp;
    vector<int> r, distances;

    fin >> n;

    for (int i = 0; i < n; i++) {
        fin >> tmp;
        r.push_back(tmp);
    }

    for (int j = 0; j < n; j++) {
        distances.push_back(find_distance_from_start(r));
        tmp = r.front();
        r.erase(r.begin());
        r.push_back(tmp);
    }

    fout << *min_element(distances.begin(), distances.end());

    return 0;
}