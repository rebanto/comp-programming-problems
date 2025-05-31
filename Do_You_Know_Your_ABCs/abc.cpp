#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int abc[7];
    for (int i = 0; i < 7; ++i) {
        cin >> abc[i];
    }

    sort(abc, abc + 7);
    cout << abc[0] << " " << abc[1] << " " << abc[6] - abc[0] - abc[1];

    return 0;
}