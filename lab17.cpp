#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node* next;
};

void output(Node* head);

int main() {
    Node* head = nullptr;

    // create linked list at head
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node* newVal = new Node;
        if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        } else {
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // deleting a node manually (still inline)
    Node* current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node* prev = head;
    for (int i = 0; i < (entry - 1); i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    if (current) {
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert node manually
    current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++) {
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    }
    Node* newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // delete full list manually
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);

    return 0;
}

void output(Node* head) {
    if (!head) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}
