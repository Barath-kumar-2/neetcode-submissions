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
    int solve(int num1, int num2){
        int a = max(num1,num2);
        int b = min(num1,num2);
        while(b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp && temp->next){
            int num1 = temp->val;
            int num2 = temp->next->val;
            int gcd = solve(num1,num2);
            ListNode* curr = new ListNode(gcd);
            ListNode* fut = temp->next;
            temp->next = curr;
            curr->next = fut;
            temp = fut;
        }
       
        return head;
    }
};