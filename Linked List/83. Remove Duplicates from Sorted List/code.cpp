class Solution {
public:

    ListNode *ret(ListNode *n ,int value){
        while(n && n->val == value){
            n = n->next;
        }
        return n;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        while(temp){
            temp->next = ret(temp ,temp->val);
            temp = temp->next;
        }
        return head;
    }
};