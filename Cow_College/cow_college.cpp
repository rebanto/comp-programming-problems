#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, temp;
    vector<int> c;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        c.push_back(temp);
    }

    sort(c.begin(), c.end());

    long long highest = 0; 
    int tuition = 0;

    for (int i = 0; i < N; i++) {
        long long revenue = (long long)c[i] * (N - i); 

        if (revenue > highest) {
            highest = revenue;
            tuition = c[i];
        }
    }

    cout << highest << " " << tuition;

    return 0;
}