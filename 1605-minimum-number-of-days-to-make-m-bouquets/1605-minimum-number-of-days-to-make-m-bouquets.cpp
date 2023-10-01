class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int l = 1, h = 1e9, n = v.size();
        if(m>(n/k)) return -1;
        while(l<h) {
            int mid = l+(h-l)/2;
            int cnt = 0, flg = 0; 
            for(int i=0; i<n; i++) {
                if(v[i]<=mid) flg++;
                else flg = 0;
                if(flg==k) {
                    cnt++;
                    flg = 0;
                }
            }
            if(cnt<m) {
                l = mid+1;
            }
            else {
                h = mid;
            }
        }
        return l;
    }
};

// ------------------------TC: O(n*log(n))---------------------
// ------------------------SC: O(1)----------------------------