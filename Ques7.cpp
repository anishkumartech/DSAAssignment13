
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

Node* reverseDoublyLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // The last node will become the new head of the reversed list
    return temp->prev;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the original doubly linked list
    Node* head = new Node(10);
    head->next = new Node(8);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;

    // Print the original linked list
    std::cout << "Original Linked list: ";
    printLinkedList(head);

    // Reverse the doubly linked list
    Node* reversed = reverseDoublyLinkedList(head);

    // Print the reversed linked list
    std::cout << "Reversed Linked list: ";
    printLinkedList(reversed);

    // Clean up memory
    while (reversed != nullptr) {
        Node* temp = reversed;
        reversed = reversed->next;
        delete temp;
    }

    return 0;
}
