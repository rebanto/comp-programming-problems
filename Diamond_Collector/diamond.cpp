#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;
    fin >> N >> K;
    vector<int> diamonds(N);

    for (int i = 0; i < N; i++) {
        fin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    int maxDiamonds = 0;
    int left = 0;
    for (int right = 0; right < N; right++) {
        while (diamonds[right] - diamonds[left] > K) {
            left++;
        }
        maxDiamonds = max(maxDiamonds, right - left + 1);
    }

    fout << maxDiamonds << endl;

    return 0;
}