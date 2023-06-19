class Solution {
public:
    void func(int i, int target, vector<int> & v, vector<int> tmp, vector<vector<int>>& ans) {
        if(i>=v.size()) {
            if(target==0) ans.push_back(tmp);
            return;
        }
        func(i+1, target, v, tmp, ans);
        if(v[i]<=target) {
            tmp.push_back(v[i]);
            func(i, target-v[i], v, tmp, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        func(0, target, v, tmp, ans);
        return ans;
    }
};