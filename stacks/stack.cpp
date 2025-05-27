#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> elements;
public:
    bool isEmpty() {
        if (elements.empty()) {
            return true;
        } else return false;
    }

    void push(int data) {  
        elements.push_back(data);
    }

    int pop() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return -1;
        }

        int topElement = elements.back();
        elements.pop_back();
        return topElement;
    }

    int peek() {
        if (isEmpty()) {
            cerr << "Stack is empty." << endl;
            return -1;
        }

        return elements.back();
    }

    int size() {
        return elements.size();
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    myStack.push(60);

    myStack.pop();
    cout << myStack.size() << endl;

    cout << myStack.peek() << endl;

    return 0;
}