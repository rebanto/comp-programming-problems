#include <fstream>
using namespace std;

int main() {
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    
    int c[3], m[3];

    for (int i = 0; i < 3; ++i) fin >> c[i] >> m[i];
    
    for (int i = 0; i < 100; ++i) {
        int from = i % 3, to = (i + 1) % 3;
        int pour = min(m[from], c[to] - m[to]);
        m[from] -= pour;
        m[to] += pour;
    }

    for (int i = 0; i < 3; ++i) fout << m[i] << '\n';
    
    return 0;
}