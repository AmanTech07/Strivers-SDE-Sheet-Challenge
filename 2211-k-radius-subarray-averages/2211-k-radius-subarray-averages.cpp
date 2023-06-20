class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(n);
        long long int sum = 0, j=0, x = 2*k+1;
        for(int i=0; i<x && i<n; i++) {
            sum += nums[i];
        }
        for(int i=0; i<n; i++) {
            if(i-k<0 || i+k>=n) {
                v[i] = -1;
                continue;
            }
            v[i] = (sum/(2*k+1));
            sum -= nums[j++];
            if(x<n) sum += nums[x++];
        }
        return v;
    }
};