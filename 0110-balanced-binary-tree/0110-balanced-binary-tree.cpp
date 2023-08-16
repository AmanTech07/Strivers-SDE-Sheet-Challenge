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
    int hgt(TreeNode* root, bool& ans) {
        if(!root) return 0;
        int lft = hgt(root->left, ans);
        int rgt = hgt(root->right, ans);
        if(abs(lft-rgt)>1) ans = false;
        return max(lft, rgt)+1;
    }

public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        hgt(root, ans);
        return ans;
    }
};