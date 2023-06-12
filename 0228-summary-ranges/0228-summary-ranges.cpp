class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        vector<pair<int, int>> v;
        v.push_back({nums[0], nums[0]});
        int k = 0;
        for(int i=1; i<n; i++) {
            if(nums[i]!=nums[i-1]+1) {
                v[k].second = nums[i-1];
                v.push_back({nums[i], nums[i]});
                k++;
            }
        }
        v[k].second = nums[n-1];
        string s;
        for(int i=0; i<=k; i++) {
            s = to_string(v[i].first);
            if(v[i].first!=v[i].second) {
                s += "->";
                string tmp = to_string(v[i].second);
                s+=tmp;
            }
            ans.push_back(s);
        }
        return ans;
    }
};