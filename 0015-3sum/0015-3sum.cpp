class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(v.begin(), v.end());
        for(int i=0; i<v.size()-2; i++) {
            int find = -v[i], l = i+1, r = v.size()-1;
            while(l<r) {
                if(v[l]+v[r]>find) {
                    r--;
                }
                else if(v[l]+v[r]==find) {
                    s.insert({v[i], v[l], v[r]});
                    l++, r--;
                }
                else l++;
            }
        }
        for(auto &x: s) ans.push_back(x);
        return ans;
    }
};