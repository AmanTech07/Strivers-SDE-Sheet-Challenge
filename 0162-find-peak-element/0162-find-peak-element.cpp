class Solution {
public:
    int findPeakElement(vector<int>& v) {
        int l = 0, h = v.size()-1, cnt = 0 ;
        if(h==0 || v[l]>v[l+1]) return 0;
        if(v[h]>v[h-1]) return h;
        while(l<h) {
            int mid = l+(h-l)/2;
            if(v[mid]>v[mid+1]) {
                h = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }
};