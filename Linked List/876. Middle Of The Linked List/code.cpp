class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slowPointer = head;
        ListNode *fastPointer = head;

        while(fastPointer != NULL && fastPointer->next != NULL){
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        return slowPointer;
    }
};