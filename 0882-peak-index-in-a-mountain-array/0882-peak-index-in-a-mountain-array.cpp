class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int l = 0, h = v.size()-1;
        while(l<h) {
            int mid = l+(h-l)/2;
            if(v[mid+1]>v[mid]) {
                l = mid+1;
            }
            else {
                h = mid;
            }
        }
        return l;
    }
};