class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        if(s.size()==0) return 0;
        int i=0, n = s.size(), flg = 1;
        while(i<n && s[i]==' ') i++;
        if(s[i]=='-') s[i++] = flg = 0;
        else if(s[i]=='+') i++;
        while(i<n && s[i]>='0' && s[i]<='9') {
            ans *= 10;
            ans += (s[i]-'0');
            if(ans>=INT_MAX && flg==1) return INT_MAX;
            else if(-ans<=INT_MIN && flg==0) return INT_MIN;
            i++;
        }
        return flg==1?ans:(-ans);
    }
};