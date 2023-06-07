class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size(), lst = -1, ind=-1;
        for(int i=0; i<n; i++) {
            if(lst>=v[i][0]) {
                lst = max(lst, v[i][1]);
                ans[ind][1] = lst;
            }
            else {
                ans.push_back({v[i][0], v[i][1]});
                ind++;
                lst = v[i][1];
            }
        }

        return ans;

        // ---------------------------TC: O(n*log(n))----------------------
        // ---------------------------SC: O(n*2)---------------------------
    }
};