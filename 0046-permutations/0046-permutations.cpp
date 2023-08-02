class Solution {
public:
    void func(int i, vector<int>& v, vector<vector<int>>& ans) {
        if(i==v.size()) {
            ans.push_back(v);
            return;
        }
        for(int j=i; j<v.size(); j++) {
            swap(v[i], v[j]);
            func(i+1, v, ans);
            swap(v[i], v[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        func(0, v, ans);
        return ans;
    }
    
    // -----------------TC: O(n!*n)------------------
    // -----------------SC: O(n)---------------------
    // We don't count the answer as part of the space complexity. The extra space we use here is for v and the recursion call stack. The depth of the call stack is equal to the length of v, which is limited to n.

};