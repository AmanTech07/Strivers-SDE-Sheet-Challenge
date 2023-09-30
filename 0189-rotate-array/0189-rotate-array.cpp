class Solution {
    void reverse_vec(vector<int> &v, int s, int e) {
        int i = s, j = e;
        while(i<j) {
            swap(v[i++], v[j--]);
        }
    }
public:
    void rotate(vector<int>& v, int k) {
        int n = v.size();
        k %= n;
        if(n==1 || k==0) return;
        reverse_vec(v, 0, n-1);
        reverse_vec(v, k, n-1);
        reverse_vec(v, 0, k-1);
    }
};