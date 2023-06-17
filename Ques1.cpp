#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

int getListSize(Node* head) {
    int size = 0;
    while (head != nullptr) {
        size++;
        head = head->next;
    }
    return size;
}

Node* createNewLinkedList(Node* list1, Node* list2) {
    int size1 = getListSize(list1);
    int size2 = getListSize(list2);
    int newSize = (size1 + size2) / 2; // Calculate the size of the new list

    if (size1 == 0)
        return list2;
    if (size2 == 0)
        return list1;

    Node* newList = nullptr;
    Node* tail = nullptr;

    // Traverse both lists simultaneously
    while (list1 != nullptr && list2 != nullptr) {
        Node* newNode;
        if (list1->data >= list2->data) {
            newNode = new Node(list1->data);
            list1 = list1->next;
        } else {
            newNode = new Node(list2->data);
            list2 = list2->next;
        }

        if (newList == nullptr) {
            newList = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        newSize--; // Decrement the size of the new list

        if (newSize == 0)
            break;
    }

    // Add the remaining nodes from the longer list
    if (newSize > 0) {
        Node* remainingList = (list1 != nullptr) ? list1 : list2;
        while (newSize > 0 && remainingList != nullptr) {
            Node* newNode = new Node(remainingList->data);
            tail->next = newNode;
            tail = newNode;
            remainingList = remainingList->next;
            newSize--;
        }
    }

    return newList;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << "->";
        head = head->next;
    }
    std::cout << std::endl;
}

Node* createLinkedListFromInput() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int size;

    std::cout << "Enter the size of the linked list: ";
    std::cin >> size;

    std::cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < size; i++) {
        int value;
        std::cin >> value;

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    // Input from the user
    std::cout << "Creating the first linked list" << std::endl;
    Node* list1 = createLinkedListFromInput();

    std::cout << "Creating the second linked list" << std::endl;
    Node* list2 = createLinkedListFromInput();

    // Create the new linked list
    Node* newList = createNewLinkedList(list1, list2);

    // Print the new linked list
    std::cout << "New list: ";
    printLinkedList(newList);

    // Clean up memory
    while (newList != nullptr) {
        Node* temp = newList;
        newList = newList->next;
        delete temp;
    }

    return 0;
}
