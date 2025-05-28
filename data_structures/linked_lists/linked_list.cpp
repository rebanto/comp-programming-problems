#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
private:
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        newNode->next = this->head;
        this->head = newNode;
    }

    void insertAtTail(int data) {
        Node* temp = head;

        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void insertAtIndex(int data, int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        Node* newNode = new Node(data);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        int ind = 0;

        while (temp != NULL && ind < index - 1) {
            temp = temp->next;
            ind++;
        }

        if (temp == NULL) {
            cout << "Invalid index." << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        int ind = 0;

        while (temp != NULL && ind < index - 1) {
            temp = temp->next;
            ind++;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid index." << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* oldHead = head;
        head = head->next;
        delete oldHead;
    }

    void deleteAtTail() {
        if (head == NULL) {
            cout << "Linked List is empty." << endl;
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = NULL;
        delete toDelete;
    }

    void displayLinkedList() {
        Node* temp = head;

        if (head == NULL) {
            cout << "Linked List is empty." << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    int getLength() {
        int length = 0;
        Node* temp = head;

        while (temp != NULL) {
            length++;
            temp = temp->next;
        }
        return length;
    }
};

int main() {
    LinkedList myLinkedList;

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