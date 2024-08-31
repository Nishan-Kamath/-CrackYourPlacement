#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *reverselist(Node *head) {
    Node *prev = nullptr, *curr = head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void printList(Node *curr) {
  
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// Function to rearrange a linked list
Node *rearrange(Node *head) {
  
    // Find the middle point using tortoise and hare method
    Node *slow = head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
  
    // Split the linked list into two halves
    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = NULL;
    
      // Reverse the second half
    head2 = reverselist(head2);
    
      // Merge alternate nodes
    head = new Node(0); 
    Node *curr = head;
    while (head1 || head2) {
      
        // First add the element from the first list
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
      
        // Then add the element from the second list
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
  
    // Return the head of the new list
    return head->next;
}


int main() {
  
     // singly linked list 1->2->3->4->5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5); 
      
    head = rearrange(head); 
    printList(head);        
    return 0;
}