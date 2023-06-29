class Solution {
public:
    int n,m,keys;
    int dx[4] = {1,-1,0,0};
    int dy[4] ={0,0,1,-1};
    int shortestPathAllKeys(vector<string>& g) {
        queue<pair<pair<int,int>,int>>q;
        n=g.size();
        m=g[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(g[i][j]=='@')q.push({{i,j},0});
            if(g[i][j]>='a' && g[i][j]<='z')keys++;
        }
        }
        int check = (1<<keys)-1;
        map<pair<pair<int,int>,int>,int>p;
        int ans=0;
        while(q.size()){
            int k=q.size();
            for(int i=0;i<k;i++){
                auto j = q.front();q.pop();
                int x = j.first.first;
                int y = j.first.second;
                int mask = j.second;
                if(mask==check)return ans;
                for(int h=0;h<4;h++){
                    int nx = x + dx[h];
                    int ny = y + dy[h];
                    if(nx>=0 && ny>=0 && ny<m && nx<n && g[nx][ny]!='#'){
                        if(g[nx][ny]>='a' && g[nx][ny]<='z'){
                            int n_mask = mask | (1<<(g[nx][ny]-'a'));
                            if(p.find({{nx,ny},n_mask})==p.end()){
                                p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                        else if(g[nx][ny]>='A' && g[nx][ny]<='Z'){
                            int c = g[nx][ny]-'A';
                            if((mask & (1<<c)) == 0)continue;
                            int n_mask = mask;
                            if(p.find({{nx,ny},n_mask})==p.end()){
                               p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                        else{
                            int n_mask = mask;
                            if(p.find({{nx,ny},n_mask})==p.end()){
                                p[{{nx,ny},n_mask}]=n_mask;
                                q.push({{nx,ny},n_mask});
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int shortestPathAllKeys(vector<string>& grid) {
//         map<char, int> mp;
//         int n = grid.size(), m = grid[0].size();
//         int x=-1, y=-1, key_cnt=0;
//         for(int i=0; i<n; i++) {
//             for(int j=0; j<m; j++) {
//                 if(grid[i][j]=='@') {
//                     grid[i][j] = '.';
//                     x = i, y = j;
//                 }
//                 if(grid[i][j]>=97 && grid[i][j]<=102) key_cnt++;
//             }
//         }
//         vector<vector<int>> vis(n, vector<int>(m, 0)), visRefresh(n, vector<int>(m, 0));
//         vector<int> row = {1, -1, 0, 0}, col = {0, 0, 1, -1};
//         queue<pair<int, int>> q;
//         q.push({x, y});
//         vis[x][y] = 1;
//         int cnt = 0, ans = 0;
//         while(!q.empty()) {
//             cnt++;
//             int sz = q.size();
//             while(sz--) {
//                 auto ele = q.front();
//                 q.pop();
//                 int a = ele.first, b = ele.second;
//                 for(int i=0; i<4; i++) {
//                     int x_pos = a+row[i], y_pos = b+col[i];
//                     if(x_pos<0 || x_pos>=n || y_pos<0 || y_pos>=m || grid[x_pos][y_pos]=='#') continue;
//                     char ch = grid[x_pos][y_pos];
//                     if(ch>=65 && ch<=70) {
//                         if(mp[(ch+32)]==1) grid[x_pos][y_pos] = '.';
//                         else continue;
//                     }
//                     else if(ch>=97 && ch<=102) {
//                         mp[ch] = 1;
//                         grid[x_pos][y_pos] = '.';
//                         ans = cnt;
//                         // vis = visRefresh;
//                         // sz = 0;
//                         // while(!q.empty()) q.pop();
//                         // q.push({x_pos, y_pos});
//                         // vis[x_pos][y_pos] = 1;
//                         // break;
//                     }
//                     if(!vis[x_pos][y_pos]) {
//                         q.push({x_pos, y_pos});
//                         vis[x_pos][y_pos] = 1;
//                     }
//                 }
//             }
//         }
//         for(auto &x: mp) if(x.second==1) key_cnt--;
//         if(key_cnt!=0) return -1;
//         return ans;
//     }
// };