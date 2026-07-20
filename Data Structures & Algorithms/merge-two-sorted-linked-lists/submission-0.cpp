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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* track = dummy;
        while(head1 && head2){
            int temp1 = head1->val;
            int temp2 = head2->val;
            if(temp1 < temp2){
                ListNode* curr = new ListNode(temp1);
                track->next = curr;
                track = track->next;
                head1 = head1->next;
            }else{
                ListNode* curr = new ListNode(temp2);
                track->next = curr;
                track = track->next;
                head2 = head2->next;
            }
        }
        while(head1){
            int temp1 = head1->val;
            ListNode* curr = new ListNode(temp1);
            track->next = curr;
            track = track->next;
            head1 = head1->next;
        }while(head2){
            int temp1 = head2->val;
            ListNode* curr = new ListNode(temp1);
            track->next = curr;
            track = track->next;
            head2 = head2->next;
        }
        return dummy->next;
    }
};
