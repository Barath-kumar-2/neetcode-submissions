/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> m;
        Node* root = new Node(node->val);
        m[node] = root;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            for(auto it : temp->neighbors){
                if(m.find(it) == m.end()){
                    Node* curr = new Node(it->val);
                    m[it] = curr;
                    q.push(it);
                }
                m[temp]->neighbors.push_back(m[it]);
            }
        }
        return root;
    }
};
