#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class LinkedListSTL {
private:
    list<int> l;
public:
    void insertAtHead(int data) {
        l.push_front(data);
    }

    void insertAtTail(int data) {
        l.push_back(data);
    }

    void insertAtIndex(int data, int index) {
        if (index < 0 || index > l.size()) {
            cout << "Invalid index." << endl;
            return;
        }
        auto it = l.begin();
        advance(it, index);
        l.insert(it, data);
    }

    void deleteAtHead() {
        if (l.empty()) {
            cout << "List is empty." << endl;
            return;
        }
        l.pop_front();
    }

    void deleteAtTail() {
        if (l.empty()) {
            cout << "Linked List is empty." << endl;
            return;
        }
        l.pop_back();
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= l.size()) {
            cout << "Invalid index." << endl;
            return;
        }
        auto it = l.begin();
        advance(it, index);
        l.erase(it);
    }

    void displayLinkedList() {
        if (l.empty()) {
            cout << "Linked List is empty." << endl;
            return;
        }
        for (auto it = l.begin(); it != l.end(); ++it) {
            cout << *it;
            if (next(it) != l.end()) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    int getLength() {
        return l.size();
    }
};

int main() {
    LinkedListSTL myLinkedList;

    myLinkedList.insertAtTail(4);
    myLinkedList.insertAtHead(10);
    myLinkedList.deleteAtTail();
    myLinkedList.insertAtIndex(30, 1);
    myLinkedList.insertAtTail(23);
    myLinkedList.insertAtHead(12);
    myLinkedList.insertAtIndex(23, 2);
    myLinkedList.deleteAtIndex(1);
    cout << myLinkedList.getLength() << endl;

    myLinkedList.displayLinkedList();
    return 0;
}
