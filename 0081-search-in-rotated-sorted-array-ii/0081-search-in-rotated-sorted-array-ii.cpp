class Solution {
public:
    bool find(vector<int>& v, int target, int l, int h) {
        if(l>v.size()-1 && h>v.size()-1) return 0;
        while(l<h) {
            int mid = l+(h-l)/2;
            if(v[mid]<target) l = mid+1;
            else h = mid;
        }
        if(v[l]==target) return 1;
        return 0;
    }

    bool search(vector<int>& v, int target) {
        int n = v.size();
        int l = 0, h = n-1;
        if(v[l]<v[h] || n==1) {
            return find(v, target, 0, n-1);
        }
        while(h>l+1) {
            if(v[l]<v[h]) break;
            int mid = l+(h-l)/2;
            if(v[mid]>v[l]) {
                l = mid;
            }
            else if(v[mid]==v[l]) l++;
            else {
                h = mid;
            }
        }
        if(l>0 && v[l-1]>v[l]) l--;
        // if(l==n-1 && v[l]==) 
        if(target<=v[n-1]) {
            l = l+1, h = n-1;
        }
        else {
            h = l, l = 0;
        }
        cout<<l<<" "<<h<<endl;
        return find(v, target, l, h);
    }
};