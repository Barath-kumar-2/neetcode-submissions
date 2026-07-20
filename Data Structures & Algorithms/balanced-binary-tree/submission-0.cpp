/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int lh = solve(root->left);
        int rh = solve(root->right);
        int ans = max(lh,rh)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int lh = solve(root->left);
        int rh = solve(root->right);
        int dif = abs(lh-rh);
        if(dif > 1){
            return false;
        }
        bool check1 = isBalanced(root->left);
        bool check2 = isBalanced(root->right);
        return (check1 && check2);

    }
};
