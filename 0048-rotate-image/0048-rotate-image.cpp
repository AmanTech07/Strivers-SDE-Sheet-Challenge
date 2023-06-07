class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0; i<(n+1)/2; i++) {
        for(int j=i; j<n-i-1; j++) {
            swap(mat[i][j],mat[j][n-i-1]);
            swap(mat[i][j],mat[n-i-1][n-j-1]);
            swap(mat[i][j],mat[n-j-1][i]);
        }
    }
    }
};