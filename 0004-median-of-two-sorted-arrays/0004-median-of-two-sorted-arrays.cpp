class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size()>v2.size()) return findMedianSortedArrays(v2, v1);
        int n = v1.size(), m = v2.size();
        int low = 0, high = n, l1, l2, h1, h2, half = (n+m+1)/2;
        while(low<=high) {
            int cut1 = low+(high-low)/2;
            int cut2 = half - cut1;
            if(cut1==0) l1 = INT_MIN;
            else l1 = v1[cut1-1];
            if(cut1==n) h1 = INT_MAX;
            else h1 = v1[cut1];
            if(cut2==0) l2 = INT_MIN;
            else l2 = v2[cut2-1];
            if(cut2==m) h2 = INT_MAX;
            else h2 = v2[cut2];
            if(l1<=h2 && l2<=h1) {
                if((n+m)&1) return max(l1, l2);
                return (max(l1, l2)+min(h1, h2))/2.0;
            }
            else {
                if(l1>h2) high = cut1-1;
                else low = cut1+1;
            }
        }
        return 0.0;
    }
};