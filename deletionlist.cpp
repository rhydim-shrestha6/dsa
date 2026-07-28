#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    Node* head;
    int size;

    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void insertFirst(int val) {
        Node* node = new Node(val);

        node->next = head;
        head = node;

        size++;
    }

    void insertLast(int val) {
        Node* node = new Node(val);

        if (head == nullptr) {
            head = node;
            size++;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = node;
        size++;
    }

    void insertIndex(int val, int position) {
        if (position == 0) {
            insertFirst(val);
            return;
        }

        if (position == size) {
            insertLast(val);
            return;
        }

        int index = 0;
        Node* temp = head;
        Node* previous = head;

        while (index < position) {
            if (index == position - 1) {
                previous = temp;
            }

            temp = temp->next;
            index++;
        }

        Node* node = new Node(val);

        previous->next = node;
        node->next = temp;

        size++;
    }

    void deleteIndex(int position) {
        if (position == 0) {
            Node* temp = head;
            head = head->next;

            delete temp;
            size--;

            return;
        }

        int index = 0;
        Node* temp = head;
        Node* previous = head;

        while (index < position) {
            if (index == position - 1) {
                previous = temp;
            }

            temp = temp->next;
            index++;
        }

        previous->next = temp->next;

        delete temp;

        size--;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.insertFirst(10);
    list.insertLast(20);
    list.insertLast(30);
    list.insertLast(40);

    cout << "Original: ";
    list.display();

    list.insertIndex(25, 2);

    cout << "After insertion: ";
    list.display();

    list.deleteIndex(2);

    cout << "After deletion: ";
    list.display();

    return 0;
}