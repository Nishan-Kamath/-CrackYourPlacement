class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = new ListNode(-1);
        newHead->next = head;

        ListNode * prev = newHead;
        ListNode * curr = head;
        
        while(curr){
            if(curr->val == val){
                ListNode *delNode = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete(delNode);
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        return newHead->next;
    }
};