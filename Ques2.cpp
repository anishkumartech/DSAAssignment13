#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

void removeDuplicates(Node* head) {
    if (head == nullptr)
        return;

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        } else {
            current = current->next;
        }
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
    Node* head = new Node(11);
    head->next = new Node(11);
    head->next->next = new Node(11);
    head->next->next->next = new Node(21);
    head->next->next->next->next = new Node(43);
    head->next->next->next->next->next = new Node(43);
    head->next->next->next->next->next->next = new Node(60);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Remove duplicates
    removeDuplicates(head);

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

