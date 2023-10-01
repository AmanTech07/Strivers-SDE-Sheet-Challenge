class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
       int i=0, j=v.size()-1;
       while(i<j) {
           int mid = i+(j-i)/2;
           if((mid%2==0 && v[mid]==v[mid+1]) || (mid&1 && v[mid]==v[mid-1])) {
               i = mid+1;
           }
           else j = mid;
       }
       return v[i];
    }
};