#include <iostream>

using namespace std;

int main() {
    int w;
    cin >> w;

    if (w < 2) {
        cout << "NO";
        return 0;
    }

    for (int a = 2; a <= 98; a += 2) {
        for (int b = 2; b <= 98; b += 2) {
            if (a + b == w) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}