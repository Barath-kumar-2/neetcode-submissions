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
        for(int i = num1; i >= 1; i--){
            if(num1%i == 0 && num2%i == 0){
                return i;
            } 
        }
        return 1;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> store1;
        ListNode* temp = head;
        while(temp && temp->next){
            int num1 = temp->val;
            int num2 = temp->next->val;
            int gcd = solve(num1,num2);
            store1.push_back(gcd);
            temp=temp->next;
        }
        int i = 0;
        temp = head;
        while(temp && i < store1.size()){
            ListNode* curr = new ListNode(store1[i]);
            i++;
            ListNode* fut = temp->next;
            temp->next = curr;
            curr->next = fut;
            temp = fut;
        }
        return head;
    }
};