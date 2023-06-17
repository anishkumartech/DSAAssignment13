
#include <iostream>

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

void deleteNodeAtPosition(Node** head, int position) {
    if (*head == nullptr)
        return;

    Node* current = *head;

    // If the head node needs to be deleted
    if (position == 1) {
        *head = current->next;
        if (*head != nullptr)
            (*head)->prev = nullptr;
        delete current;
        return;
    }

    // Traverse to the node at the given position
    int count = 1;
    while (current != nullptr && count < position) {
        current = current->next;
        count++;
    }

    // If the node at the given position is not found
    if (current == nullptr)
        return;

    // Update the pointers of the adjacent nodes
    if (current->prev != nullptr)
        current->prev->next = current->next;
    if (current->next != nullptr)
        current->next->prev = current->prev;

    // Delete the node
    delete current;
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
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;

    // Print the original linked list
    std::cout << "Original Linked list: ";
    printLinkedList(head);

    // Delete a node at a given position
    int position = 3;
    deleteNodeAtPosition(&head, position);

    // Print the updated linked list
    std::cout << "Updated Linked list: ";
    printLinkedList(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
