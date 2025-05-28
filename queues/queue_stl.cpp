#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    if (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    if (!q.empty()) {
        cout << q.front() << endl;
    }

    cout << q.size() << endl;

    return 0;
}
