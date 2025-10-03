#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node {
    float value;
    Node* next;
};

void output(Node* head);
void addToFront(Node*& head, float value);
void addToTail(Node*& head, float value);
void deleteNode(Node*& head, int position);
void insertNode(Node*& head, int position, float value);
void deleteList(Node*& head);

int main() {
    Node* head = nullptr;

    for (int i = 0; i < SIZE; i++) {
        addToFront(head, rand() % 100);
    }
    output(head);

    int pos;
    cout << "Which node to delete? ";
    cin >> pos;
    deleteNode(head, pos);
    output(head);

    cout << "After which node to insert 10000? ";
    cin >> pos;
    insertNode(head, pos, 10000);
    output(head);

    cout << "Deleting entire list...\n";
    deleteList(head);
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

void addToFront(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void addToTail(Node*& head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(Node*& head, int position) {
    if (!head) return;
    Node* current = head;
    if (position == 1) {
        head = head->next;
        delete current;
        return;
    }
    Node* prev = nullptr;
    for (int i = 1; current && i < position; i++) {
        prev = current;
        current = current->next;
    }
    if (!current) return;
    prev->next = current->next;
    delete current;
}

void insertNode(Node*& head, int position, float value) {
    if (position <= 0) return;
    Node* newNode = new Node;
    newNode->value = value;
    if (position == 1 && !head) {
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    Node* current = head;
    Node* prev = nullptr;
    for (int i = 0; current && i < position; i++) {
        prev = current;
        current = current->next;
    }
    newNode->next = current;
    prev->next = newNode;
}

void deleteList(Node*& head) {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}
