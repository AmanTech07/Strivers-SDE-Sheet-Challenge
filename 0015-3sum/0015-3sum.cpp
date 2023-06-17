class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        for(int i=0; i<v.size()-2; i++) {
            int find = -v[i], l = i+1, r = v.size()-1;
            while(l<r) {
                if(v[l]+v[r]>find) {
                    r--;
                }
                else if(v[l]+v[r]==find) {
                    ans.push_back({v[i], v[l], v[r]});
                    int k = l, p = r;
                    while(l<r && v[k]==v[l]) l++;
                    while(l<r && v[p]==v[r]) r--;
                }
                else l++;
            }
            int flg = v[i];
            while(i<v.size() && v[i]==flg) i++;
            i--;
        }
        return ans;
    }
};