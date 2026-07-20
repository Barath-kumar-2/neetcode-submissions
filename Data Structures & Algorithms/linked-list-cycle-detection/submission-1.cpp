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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && slow && fast->next && slow){
            fast = fast->next->next;
            slow = slow->next;
            if(fast && slow && (fast->val == slow->val)){
                return true;
            }
            if(!fast || !slow){
                return false;
            }
        }
        return false;
    }
};
