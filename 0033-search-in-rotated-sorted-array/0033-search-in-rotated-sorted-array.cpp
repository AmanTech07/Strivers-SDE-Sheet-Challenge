class Solution {
public:
    int search(vector<int>& v, int target) {
        int l = 0, h = v.size()-1;
        while(l<h && v[0]>v[v.size()-1]) {
            int mid = l+(h-l)/2;
            if(v[mid]>v[l]) {
                l = mid;
            }
            else {
                h = mid;
            }
        }
        int partition = l;
        if(target<v[0]) {
            l = partition+1, h = v.size()-1;
            while(l<h) {
                int mid = l+(h-l)/2;
                if(v[mid]<target) {
                    l = mid+1;
                }
                else h = mid;
            }
            if(l<v.size() && v[l]==target) return l;
        }
        else {
            l = 0;
            while(l<h) {
                int mid = l+(h-l)/2;
                if(v[mid]<target) {
                    l = mid+1;
                }
                else h = mid;
            }
            if(l<v.size() && v[l]==target) return l;
        }
        return -1;
    }
};