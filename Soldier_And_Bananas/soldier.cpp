#include <iostream>

using namespace std;

int main() {
    int k, n, w;
    int count = 1, amount = 0;

    cin >> k >> n >> w;

    for (int i = 0; i < w; i++) {
        amount += count * k;
        count++;
    }

    int to_borrow = amount - n;
    if (to_borrow < 0) {
        cout <<  0;
    } else cout << to_borrow;

    return 0;
}