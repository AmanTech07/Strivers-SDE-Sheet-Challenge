#define ll long long int
class Solution {
public:
    ll merge(vector<int> &v, int l, int m, int r) {
        vector<ll> tmp(r-l+1);
        ll i=l, j=m+1, k=0, cnt=0;
        for(int p=j; p<=r; p++) {
            int ind = upper_bound(v.begin()+l, v.begin()+m+1, (2LL*v[p]))-v.begin();
            if(ind<m+1) cnt = cnt+(m-ind+1);
        }
        while(i<=m && j<=r) {
            if(v[i]>v[j]) tmp[k++] = v[j++];
            else tmp[k++] = v[i++];
        }
        while(i<=m) tmp[k++] = v[i++];
        while(j<=r) tmp[k++] = v[j++];
        for(int x=0; x<=(r-l); x++) {
            v[l+x] = tmp[x];
        }
        return cnt;
    }

    ll mergeSort(vector<int> &v, int l, int h) {
        if(l==h) return 0;
        ll mid = l+(h-l)/2;
        ll cnt = mergeSort(v, l, mid);
        cnt = cnt + mergeSort(v, mid+1, h);
        cnt = cnt + merge(v, l, mid, h);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        ll cnt = mergeSort(nums, 0, nums.size()-1);
        return cnt;
    }
};