#include <iostream>

using namespace std;

int main() {
    long long k, n, w;
    cin >> k >> n >> w;

    long long total_cost = k * w * (w + 1) / 2;

    long long to_borrow = total_cost - n;

    if (to_borrow < 0) {
        cout << 0;
    } else {
        cout << to_borrow;
    }

    return 0;
}