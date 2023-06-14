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
    // void dfs(TreeNode* root, vector<int>& v) {
    //     if(!root) return;
    //     dfs(root->left, v);
    //     v.push_back(root->val);
    //     dfs(root->right, v);
    // }

    int ans = INT_MAX, num = -1;
    int getMinimumDifference(TreeNode* root) {
        // vector<int> v;
        // dfs(root, v);
        // int mini=INT_MAX;
        // for(int i=1; i<v.size(); i++) {
        //     mini = min(mini, v[i]-v[i-1]);
        // }
        // return mini;
        if(root->left) getMinimumDifference(root->left);
        if(num>=0) ans = min(ans, root->val-num);
        num = root->val;
        if(root->right) getMinimumDifference(root->right);
        return ans;
    }
};