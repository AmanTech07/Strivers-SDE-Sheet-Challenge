class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        if(v1.size()>v2.size()) return findMedianSortedArrays(v2, v1);
        int n1=v1.size(), n2=v2.size();
        int l = 0, h = n1, l1, l2, r1, r2, take = (n1+n2+1)/2;
        while(l<=h) {
            int cut1 = l+(h-l)/2;
            int cut2 = take-cut1;
            if(cut1==0) l1 = INT_MIN;
            else l1 = v1[cut1-1];
            if(cut2==0) l2 = INT_MIN;
            else l2 = v2[cut2-1];
            if(cut1==n1) r1 = INT_MAX;
            else r1 = v1[cut1];
            if(cut2==n2) r2 = INT_MAX;
            else r2 = v2[cut2];
            if(l1<=r2 && l2<=r1) {
                if((n1+n2)&1) return max(l1, l2);
                else return (max(l1, l2)+min(r1, r2))/2.0;
            }
            else if(l1>r2) {
                h = cut1-1;
            }
            else if(l2>r1) {
                l = cut1+1;
            }
        }
        return 0.0;
    }
};