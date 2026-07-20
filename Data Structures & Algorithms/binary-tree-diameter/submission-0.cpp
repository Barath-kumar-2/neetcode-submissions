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
    int solve(TreeNode* root, int &ans){
        if(!root){
            return 0;
        }
        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);
        int temp = lh+rh;
        ans = max(ans, temp); 
        int res = max(lh,rh)+1;
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int h = solve(root, ans);
        return ans;
    }
};
