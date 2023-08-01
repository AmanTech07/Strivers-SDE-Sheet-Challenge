class Solution {
public:
    void func(int i, int k, int n, vector<int>& v, vector<vector<int>>& ans) {
        if(k==0) {
            ans.push_back(v);
            return;
        }
        if(i>n) return;
        v.push_back(i);
        func(i+1, k-1, n, v, ans);
        v.pop_back();
        func(i+1, k, n, v, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        func(1, k, n, v, ans);
        return ans;
    }
};