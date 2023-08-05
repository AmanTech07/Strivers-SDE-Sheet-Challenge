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
    vector<TreeNode*> func(int l, int r) {
        vector<TreeNode*> v;
        if(l>r || l<1) {
            v.push_back(NULL);
            return v;
        }
        if(l==r) {
            TreeNode* node = new TreeNode(l);
            v.push_back(node);
            return v;
        }
        for(int i=l; i<=r; i++) {
            vector<TreeNode*> lt = func(l, i-1);
            vector<TreeNode*> rt = func(i+1, r);
            // nested loop
            for(auto &x: lt) {
                for(auto &y: rt) {
                    TreeNode* root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    v.push_back(root);
                }
            }
        }
        return v;
    }

    vector<TreeNode*> generateTrees(int n) {
        return func(1, n);
    }
};