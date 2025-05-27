#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);

    if (!myStack.empty()) {
        myStack.pop();
    }
    cout << myStack.size() << endl;

    if (!myStack.empty()) {
        cout << myStack.top() << endl;
    } else {
        cout << "Stack is empty." << endl;
    }

    return 0;
}
