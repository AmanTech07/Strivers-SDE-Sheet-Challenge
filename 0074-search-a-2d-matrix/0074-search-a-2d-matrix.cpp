class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int l = 0, h = v.size()-1, m = v[0].size()-1, r;
        while(l<h) {
            int mid = l + (h-l)/2;
            if(v[mid][m]>=target) {
                h = mid;
            }
            else {
                l = mid+1;
            }
        }
        r = h, l = 0, h = m;
        while(l<h) {
            int mid = l+(h-l)/2;
            if(v[r][mid]>=target) {
                h = mid;
            }
            else {
                l = mid+1;
            }
        }
        if(v[r][l]==target) return 1;
        return 0;
    }
};