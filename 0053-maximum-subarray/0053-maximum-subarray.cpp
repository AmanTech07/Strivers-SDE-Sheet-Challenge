class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int maxi = INT_MIN, tmp = 0, n = v.size();
        for(int i=0; i<n; i++) {
            tmp += v[i];
            maxi = max(maxi, tmp);
            if(tmp<0) tmp = 0;
        }
        return maxi;

        // -----------------TC: O(n)-----------------
        // -----------------SC: O(1)-----------------
    }
};