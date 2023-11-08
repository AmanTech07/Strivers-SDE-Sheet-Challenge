class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dif1 = abs(fx-sx), dif2 = abs(fy-sy);
        int ans = max(dif1, dif2); 
        if(ans==0 && t==1) return false;
        return ans<=t;
    }
};