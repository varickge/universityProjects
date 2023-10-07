#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp; 
            } else {
                current = current->next;
            }
        }
        
        return head;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a sample linked list with duplicates
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    std::cout << "Linked List after removing duplicates: ";
    printList(result);

    // Clean up memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}


//Result
// Original Linked List: 1 -> 1 -> 2 -> 3 -> 3 -> nullptr
// Linked List after removing duplicates: 1 -> 2 -> 3 -> nullptr