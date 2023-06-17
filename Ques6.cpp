#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

Node* mergeSortedLists(Node* a, Node* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    Node* result = nullptr;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeSortedLists(a->next, b);
    } else {
        result = b;
        result->next = mergeSortedLists(a, b->next);
    }

    return result;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create the first linked list
    Node* a = new Node(5);
    a->next = new Node(10);
    a->next->next = new Node(15);

    // Create the second linked list
    Node* b = new Node(2);
    b->next = new Node(3);
    b->next->next = new Node(20);

    // Print the original linked lists
    std::cout << "List a: ";
    printLinkedList(a);
    std::cout << "List b: ";
    printLinkedList(b);

    // Merge the sorted lists
    Node* merged = mergeSortedLists(a, b);

    // Print the merged list
    std::cout << "Merged List: ";
    printLinkedList(merged);

    // Clean up memory
    while (merged != nullptr) {
        Node* temp = merged;
        merged = merged->next;
        delete temp;
    }

    return 0;
}

