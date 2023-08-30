class Solution {
public:
    long long minimumReplacement(vector<int>& v) {
        int n = v.size()-2;
        long long cnt = 0;
        while(n>=0) {
            if(v[n]>v[n+1]) {
                int r = v[n]%v[n+1], q = (v[n]/v[n+1]);
                if(r==0) {
                    cnt += (q-1);
                    v[n] = v[n+1];
                }
                else {
                    cnt += q;
                    v[n] /= (q+1);
                }
            }
            n--;
        }
        return cnt;
    }
};