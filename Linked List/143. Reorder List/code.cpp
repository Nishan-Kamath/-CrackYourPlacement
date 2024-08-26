class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;

        vector<ListNode*> v;
        ListNode* temp = head;

        while(temp){
            v.push_back(temp);
            temp = temp->next;
        }

        int i=0,j=v.size()-1;
        ListNode* prev = NULL;
        
        while(i<=j){
            if(i!=0)
                prev->next = v[i];
            if(i!=j)
                v[i]->next = v[j];

            prev = v[j];
            i++;
            j--;
        }
        prev->next = NULL;
    }
};