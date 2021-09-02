class Solution {
public:
    int size(ListNode* head){
        int sz = 0;
        while(head != nullptr){
            head = head->next;
            sz++;
        }
        return sz;
    }
    ListNode* middleNode(ListNode* head) {
        int idx = size(head) / 2;
        ListNode* ret = head;
        for(int i = 0; i < idx; i++){
            ret = ret->next;
        }
        return ret;
    }
};