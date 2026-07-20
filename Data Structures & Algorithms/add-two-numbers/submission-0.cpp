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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        int carry = 0;
        while(l1 && l2){
            int temp1 = l1->val;
            int temp2 = l2->val;
            int sum = temp1+temp2+carry;
            int digit = sum%10;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = temp;
        }
        while(l1){
            int temp1 = l1->val;
            int sum = temp1+carry;
            int digit = sum%10;
            carry = sum/10;
            l1 = l1->next;
            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = temp;
        }
        while(l2){
            int temp1 = l2->val;
            int sum = temp1+carry;
            int digit = sum%10;
            carry = sum/10;
            l2 = l2->next;
            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = temp;
        }
        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = temp;
        }
        return dummy->next;
    }
};
