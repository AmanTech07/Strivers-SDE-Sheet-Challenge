class Solution {
public:
    void func(int cur, int target, vector<int>& v, vector<int>& tmp, vector<vector<int>>& ans) {
        if(target==0) {
            ans.push_back(tmp);
            return;
        }
        for(int i=cur; i<v.size(); i++) {
            if(i!=cur && v[i]==v[i-1]) continue;
            if(v[i]>target) break;
            tmp.push_back(v[i]);
            func(i+1, target-v[i], v, tmp, ans);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        func(0, target, candidates, tmp, ans);
        return ans;
    }
};