class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int n = v.size(), pos=0, pos1=0;
        for(int i=n-1; i>0; i--) {
            if(v[i]>v[i-1]) {
                pos = i;
                break;
            }
        }
        if(pos!=0) {
            pos1 = pos;
            int mini = v[pos];
            for(int i=pos; i<n; i++) {
                if(v[i]>v[pos-1] && v[i]<mini) {
                    mini = v[i];
                    pos1 = i;
                } 
            }
            swap(v[pos-1], v[pos1]);
        }
        sort(v.begin()+pos, v.end());
    }
};