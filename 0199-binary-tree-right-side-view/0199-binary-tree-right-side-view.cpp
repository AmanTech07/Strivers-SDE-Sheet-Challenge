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
    void traversal(TreeNode* root, int level, int& maxi, vector<int>& ans) {
        if(!root) return;
        if(level>maxi) ans.push_back(root->val);
        maxi = max(maxi, level);
        traversal(root->right, level+1, maxi, ans);
        traversal(root->left, level+1, maxi, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0, maxi = -1;
        traversal(root, level, maxi, ans);
        return ans;
    }
};