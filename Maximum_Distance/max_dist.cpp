#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < n; ++i) cin >> y[i];

    int max_dist2 = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            int dist2 = dx * dx + dy * dy;
            max_dist2 = max(max_dist2, dist2);
        }
    }
    
    cout << max_dist2 << endl;
}