class Solution {
public:
    int splitArray(vector<int>& v, int k) {
        int l = 0, h = 0, n = v.size(), ans = 0;
        for(int i=0; i<n; i++) h += v[i];
        while(l<h) {
            int mid = l+(h-l)/2;
            int sum = 0, split = 1;
            for(int i=0; i<n; i++) {
                sum += v[i];
                if(sum>mid) {
                    sum = v[i];
                    split++;
                }
            }
            if(split>k) {
                l = mid+1;
            }
            else h = mid;
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += v[i];
            if(sum>l) sum = v[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};