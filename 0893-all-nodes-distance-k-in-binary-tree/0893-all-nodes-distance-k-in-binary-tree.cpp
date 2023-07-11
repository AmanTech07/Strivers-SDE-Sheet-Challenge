/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> m;
    void dfs(TreeNode* root, TreeNode* target, TreeNode* parent) {
        if(!root) return;
        m[root] = parent;
        if(root==target) return;
        dfs(root->left, target, root);
        dfs(root->right, target, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* parent = NULL;
        dfs(root, target, parent);
        queue<TreeNode*> q;
        q.push(target);
        vector<int> vis(501, 0), ans;
        vis[target->val] = 1;
        int level = 0;
        while(!q.empty() && level<=k) {
            int sz = q.size();
            level++;
            while(sz--) {
                auto node = q.front();
                q.pop();
                if(node->left && vis[node->left->val]==0) {
                    q.push(node->left);
                    vis[node->left->val] = 1;
                }
                if(node->right && vis[node->right->val]==0) {
                    q.push(node->right);
                    vis[node->right->val] = 1;
                }
                if(m[node] && vis[m[node]->val]==0) {
                    q.push(m[node]);
                    vis[m[node]->val] = 1;
                }
                if(level==k+1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};