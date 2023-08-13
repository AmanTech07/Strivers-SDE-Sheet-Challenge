class Solution {
public:
    map<pair<int, int>, int> r, c;
    bool isRepeating(int i, int j, vector<vector<char>>& v, char ch) {
        int x=0, y=0;
        if(j>=6) y = 6;
        else if(j>=3) y = 3; 
        if(i>=6) x = 6;
        else if(i>=3) x = 3;
        for(int row=0; row<3; row++) {
            for(int col=0; col<3; col++) {
                if(v[row+x][col+y]==ch) return true;
            }
        }
        return false;
    }

    bool func(int i, int j, vector<vector<char>>& v) {
        if(i==9) {
            return 1;
        }
        if(j==9) {
            return func(i+1, j%9, v);
        }
        if(v[i][j]=='.') {
            for(int k=1; k<=9; k++) {
                char ch = k+'0';
                if(r[{i, k}]==1 || c[{j, k}]==1 || isRepeating(i, j, v, ch)) continue;
                v[i][j] = ch;
                r[{i, k}] = 1;
                c[{j, k}] = 1;
                if(func(i, j+1, v)) return 1;
                v[i][j] = '.';
                r[{i, k}] = 0;
                c[{j, k}] = 0;
            }
        }
        else return func(i, j+1, v);
        return false;
    }

    void solveSudoku(vector<vector<char>>& v) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(v[i][j]!='.') {
                    r[{i, v[i][j]-'0'}] = 1;
                    c[{j, v[i][j]-'0'}] = 1; 
                }
            }
        }
        func(0, 0, v);
    }
};