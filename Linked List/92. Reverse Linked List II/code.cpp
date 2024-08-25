class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(!head || !head->next)
            return head;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || !head->next || left==right)
            return head;
        
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        ListNode* preLeft = temp;

        for(int i=1;i<left;i++)
            preLeft = preLeft->next;

        ListNode* l = preLeft->next;
        ListNode* r = l;

        for(int i=left;i<right;i++)
            r = r->next;

        ListNode* postRight = r->next;
        r->next = NULL;

        preLeft->next = reverse(l);
        l->next = postRight;

        ListNode* newHead = temp->next;
        return newHead;

    }
};