class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0, cnt = 0;
        for(int i=0; i<gain.size(); i++) {
            cnt += gain[i];
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};