/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int index = 1;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* first = NULL;
        ListNode* bfirst = NULL;
        while(index <= right){
            if(index == left){
                first = curr;
            }
            if(index == left-1){
                bfirst = curr;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        ListNode* last = curr;
        ListNode* pst = NULL;
        curr = first;
        for(int i = 0; i < right-left+1; i++){
            ListNode* fut = curr->next;
            curr->next = pst;
            pst = curr;
            curr = fut;
        }
        first->next = last;
        if(!bfirst){
            return pst;
        }
        bfirst->next = pst;
        
        
        return head;
    }
};