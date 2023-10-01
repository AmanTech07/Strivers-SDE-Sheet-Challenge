class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()), h = accumulate(weights.begin(), weights.end(), 0), n = weights.size();
        while(l<h) {
            int mid = l+(h-l)/2;
            int cnt = 0, sum = 0;
            for(int i=0; i<n; i++) {
                if(sum+weights[i]>mid) {
                    cnt++;
                    sum = 0;
                }
                sum += weights[i];
            }
            if(sum>0) cnt++;
            if(cnt>days) {
                l = mid+1;
            }
            else {
                h = mid;
            }
        }
        return l;
    }
};

// ------------------TC: O(n*log(n))----------------
// ------------------SC: O(1)-----------------------