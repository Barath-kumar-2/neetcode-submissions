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
    void reorderList(ListNode* head) {
        ListNode* track = head;
        vector<int> store;
        while(track){
            store.push_back(track->val);
            track = track->next;
        }
        int n = store.size();
        int i = 0;
        int j = n-1;
        track = head;
        int k = 0;
        while(track){
            if(k%2 == 0){
                track->val = store[i];
                i++;
            }else{
                track->val = store[j];
                j--;
            }
            k++;
            track = track->next;
        }
    }
};
