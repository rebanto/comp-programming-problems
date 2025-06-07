#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

int main() {
    ofstream fout("blocks.out");
    ifstream fin("blocks.in");
    int N;
    vector<pair<string, string>> blocks;
    string tmp1, tmp2;
    int copies_required[26] = {0};

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> tmp1 >> tmp2;
        blocks.push_back({tmp1, tmp2});
    }

    for (const auto& block : blocks) {
        int count1[26] = {0}, count2[26] = {0};
        for (char c : block.first) {
            count1[c - 'a']++;
        }
        for (char c : block.second) {
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            copies_required[i] += max(count1[i], count2[i]);
        }
    }

    for (int i = 0; i < 26; ++i) {
        fout << copies_required[i] << endl;
    }

    return 0;
}