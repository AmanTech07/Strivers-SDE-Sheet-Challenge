class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& bus, vector<int>& pas, int cap) {
        sort(bus.begin(), bus.end());
        sort(pas.begin(), pas.end());
        int prev = 0, i = 0, j = 0, n = bus.size(), m = pas.size();
        int k = 0, ans = 0;
        while(i<n && j<m) {
            for(int k=0; k<cap && j<m; k++) {
                if(pas[j]>bus[i]) {
                    if(prev!=bus[i]) ans = bus[i];
                    break;
                }
                if(prev!=pas[j]-1) {
                    ans = max(ans, (pas[j]-1));
                }
                prev = pas[j];
                j++;
                if(j==m && k<(cap-1)) {
                    if(prev!=bus[i]) ans = bus[i];
                }
            }
            i++;
        }
        if(i<n) {
            if(prev!=bus[n-1]) ans = max(ans, bus[n-1]);
        }
        return ans;
    }
};