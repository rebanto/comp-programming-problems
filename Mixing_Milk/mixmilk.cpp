#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream fout("mixmilk.out");
    ifstream fin("mixmilk.in");

    int c[3], m[3], pours = 0, current = 0;

    for (int i = 0; i < 3; i++) {
        fin >> c[i] >> m[i];
    }

    while (pours < 100) {
        switch (current)
        {
        case 0:
            if (m[current] + m[current + 1] <= c[current + 1]) {
                m[current + 1] += m[current];
                m[current] = 0;
            } else if (m[current] + m[current + 1] > c[current + 1]) {
                m[current] = m[current + 1] + m[current] - c[current + 1];
                m[current + 1] = c[current + 1];
            }

            current++;
            break;
        case 1:
            if (m[current] + m[current + 1] <= c[current + 1]) {
                m[current + 1] += m[current];
                m[current] = 0;
            } else if (m[current] + m[current + 1] > c[current + 1]) {
                m[current] = m[current + 1] + m[current] - c[current + 1];
                m[current + 1] = c[current + 1];
            }

            current++;
            break;
        case 2:
            if (m[current] + m[0] <= c[0]) {
                m[0] += m[current];
                m[current] = 0;
            } else if (m[current] + m[0] > c[0]) {
                m[current] = m[0] + m[current] - c[0];
                m[0] = c[0];
            }

            current = 0;
            break;
        }

        pours++;
    }

    for (int i = 0; i < 3; i++) {
        fout << m[i] << endl;
    }

    return 0;
}