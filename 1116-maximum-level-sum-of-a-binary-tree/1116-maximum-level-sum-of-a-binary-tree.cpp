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
    void bfs(TreeNode* root, int level, vector<int>& lsum) {
        if(!root) return;
        if(level>lsum.size()) lsum.push_back(root->val);
        else lsum[level-1] += root->val;
        bfs(root->left, level+1, lsum);
        bfs(root->right, level+1, lsum);
    }

    int maxLevelSum(TreeNode* root) {
        int level=1, maxi=INT_MIN;
        vector<int> lsum;
        bfs(root, level, lsum);
        for(int i=0; i<lsum.size(); i++) {
            cout<<lsum[i]<<endl;
            if(maxi<lsum[i]) {
                maxi = lsum[i];
                level = i+1;
            } 
        }
        return level;
    }
};