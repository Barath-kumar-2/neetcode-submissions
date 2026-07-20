/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* track = head;
        if(!head){
            return head;
        }
        while(track){
            Node* temp = new Node(track->val);
            Node* fut = track->next;
            track->next = temp;
            temp->next = fut;
            track = fut;
        }
        track = head;
        Node* prev = NULL;
        while(track){
           Node* temp = track->random;
           Node* fut = track->next;
           if(temp){
            fut->random = temp->next;
           }
           track = fut->next;
        }
        track = head;
        Node* res = head->next;
        while(track){
            Node*fut = track->next;
            track->next = fut->next;
            track = fut->next;
            if(!track){
                break;
            }
            fut->next = track->next;
        }
        return res;
    }
};
