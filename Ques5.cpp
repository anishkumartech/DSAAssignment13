#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void deleteLastOccurrence(Node* head, int key) {
    if (head == nullptr)
        return;

    Node* lastOccur = nullptr;
    Node* prevLastOccur = nullptr;
    Node* current = head;
    Node* prev = nullptr;

    // Traverse the linked list to find the last occurrence of the key
    while (current != nullptr) {
        if (current->data == key) {
            lastOccur = current;
            prevLastOccur = prev;
        }
        prev = current;
        current = current->next;
    }

    // If the last occurrence is found, delete it
    if (lastOccur != nullptr) {
        if (prevLastOccur != nullptr) {
            prevLastOccur->next = lastOccur->next;
        } else {
            head = lastOccur->next;
        }
        delete lastOccur;
    }
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(10);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Delete the last occurrence of key
    int key = 2;
    deleteLastOccurrence(head, key);

    // Print the modified linked list
    std::cout << "Modified List: ";
    printLinkedList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

