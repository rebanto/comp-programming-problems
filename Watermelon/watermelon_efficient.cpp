#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream fin("watermelon.in");
    ofstream fout("watermelon.out");
    int w;
    fin >> w;

    cout << w << endl;

    if (w % 2 == 0 && w > 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}