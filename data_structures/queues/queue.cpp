#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Queue
{
private:
    vector<int> elements;
public:
    void push(int element) {
        elements.push_back(element);
    }

    bool isEmpty() {
        if (elements.empty()) {
            return true;
        } else return false;
    }

    int pop() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        int firstElement = elements.front();
        elements.erase(elements.begin());
        return firstElement;
    }

    int front() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return elements.front();
    }

    int back() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return elements.back();
    }

    int size() {
        return elements.size();
    }
};

int main() {
    Queue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);
    queue.push(50);
    queue.push(60);

    cout << queue.pop() << endl;
    cout << queue.front() << endl;
    cout << queue.size() << endl;
}