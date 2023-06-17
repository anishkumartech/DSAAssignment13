#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

Node* reverseKNodes(Node* head, int k) {
    if (head == nullptr)
        return nullptr;

    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    // Reverse the first k nodes
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Recursive call for the remaining list
    if (next != nullptr) {
        head->next = reverseKNodes(next, k);
    }

    return prev;
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
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Reverse every k nodes
    int k = 4;
    head = reverseKNodes(head, k);

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

