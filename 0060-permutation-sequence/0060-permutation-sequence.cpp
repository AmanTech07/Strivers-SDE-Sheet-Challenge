class Solution {
public:
    string ans;
    void func(int n, int k, string& s, vector<int>& fact) {
        if(n==1) {
            ans.push_back(s[0]);
            return;
        }
        int num = fact[n]/n;
        int x = k/num;
        ans.push_back(s[x]);
        s.erase(x, 1);
        int mod = k%num;
        func(n-1, mod, s, fact);
    }

    string getPermutation(int n, int k) {
        string s = ""; 
        vector<int> fact(n+1);
        fact[0] = 1;
        for(int i=1; i<=n; i++) {
            s += (i+'0');
            fact[i] = i*fact[i-1];
        }
        func(n, k-1, s, fact);
        return ans;
    }
};