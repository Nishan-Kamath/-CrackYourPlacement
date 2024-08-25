class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* ptr = head;
        vector<int> v;

        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        sort(v.begin(),v.end());
        ptr = head;
        int count = 0;

        while(ptr){
            ptr->val = v[count++];
            ptr = ptr->next;
        }

        return head;
    }
};