#include <fstream>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> swaps;
vector<int> guesses;
int numCorrect[3];

int findNumCorrect(int pebbleStart) {
    int shells[] = {0, 0, 0};
    shells[pebbleStart - 1] = 1;
    int i = 0;

    for (auto& swap : swaps) {
        int temp = shells[swap.first - 1];
        shells[swap.first - 1] = shells[swap.second - 1];
        shells[swap.second - 1] = temp;

        if (shells[guesses[i] - 1] == 1) {
            numCorrect[pebbleStart - 1] += 1;
        }

        i++;
    }
}

int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");

    fin >> N;

    for (int i = 0; i < N; i++) {
        int a, b, g;
        fin >> a >> b >> g;
        swaps.push_back({a, b});
        guesses.push_back(g);
    }

    for (int i = 1; i <= 3; i++) {
        findNumCorrect(i);
    }
    int max_num_correct = *max_element(numCorrect, numCorrect + 3);
    fout << max_num_correct << endl;

    return 0;
}