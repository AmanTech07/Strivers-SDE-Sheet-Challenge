class Solution {
public:
    
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int ans = 0, mini = v[0];
        for(int i=0; i<n; i++) {
            if(v[i]<mini) {
                mini = v[i];
            }
            ans = max(ans, v[i]-mini);
        }
        return ans;

        // ---------------------TC: O(n)----------------------
        // ---------------------SC: O(1)----------------------
    }
};