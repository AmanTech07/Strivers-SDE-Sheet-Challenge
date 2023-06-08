class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long m = n;
        if(n<0) m = m*(-1LL);
        while(m>0) {
            if(m&1) {
                ans = ans*x;
                m = m-1;
            }
            else {
                x = x*x;
                m = m>>1;
            }
        } 
        if(n<0) ans = 1/ans;
        return ans;
    }
};