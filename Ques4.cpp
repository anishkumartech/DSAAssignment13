#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

Node* reverseAlternateKNodes(Node* head, int k, bool reverse) {
    if (head == nullptr)
        return nullptr;

    Node* current = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    int count = 0;

    // Reverse the first k nodes if the reverse flag is true
    while (current != nullptr && count < k && reverse) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Skip the next k nodes if the reverse flag is false
    if (!reverse) {
        while (current != nullptr && count < k) {
            prev = current;
            current = current->next;
            count++;
        }
    }

    // Recursively reverse the alternate k nodes
    if (current != nullptr && count >= k && !reverse) {
        prev->next = reverseAlternateKNodes(current, k, true);
    } else if (prev != nullptr && count < k && reverse) {
        prev->next = reverseAlternateKNodes(prev->next, k, false);
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->next->next->next = new Node(9);

    // Print the original linked list
    std::cout << "Original List: ";
    printLinkedList(head);

    // Reverse every alternate k nodes
    int k = 3;
    head = reverseAlternateKNodes(head, k, true);

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
