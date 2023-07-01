class Solution {
public:
    int n;
    int MaxBomb = 1;
    vector<vector<int>> adj;

    // Print the information of bombs
    void print(vector<vector<int>>& bombs){
        cout << "n=" << n << endl;
        for(vector<int> b : bombs)
            cout << b[0] << "," << b[1] << "," << b[2] << endl;
    }

    // Print the adjacent list information
    void print_adj(){
        cout << "=======\nadj lists:\n";
        for(int i=0; i<n; i++){
            cout << i << ":[";
            for(int j=0; j<adj[i].size(); j++)
                cout << adj[i][j] << ",";
            cout << "]" << endl;
        }
    }

    // Create the adjacent list
    void create_adj(vector<vector<int>>& bombs){
        for(int i=0; i<n; i++){
            long long r = bombs[i][2], x = bombs[i][0], y = bombs[i][1];
            for(int j=0; j<n; j++){
                if(i != j){
                    double xd = bombs[j][0] - x, yd = bombs[j][1] - y;
                    if (abs(xd) + abs(yd) <= r) 
// If the distance is less than or equal to the radius, it might be very close to bomb[i]
                        
                        adj[i].push_back(j);
                    else if (r*r >= xd*xd + yd*yd) 
// If the distance satisfies condition (1)
                        adj[i].push_back(j);
                }
            }
        }
    }

    vector<bool> detonated;

    // Use Depth-First Search (DFS) recursively to calculate the number of bombs in the detonation range
    void dfs(int i){
        MaxBomb++;
        detonated[i] = 1;
        for(int j : adj[i]){
            if(!detonated[j])
                dfs(j);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();

        // Sort the bombs in descending order based on the radius
        sort(bombs.begin(), bombs.end(),
        [](vector<int>& a, vector<int>& b ){
            if(a[2] != b[2]) return a[2] > b[2];
            return a[1] > b[1];
        });

        // Print the sorted bombs information
        print(bombs);

        adj.resize(n);
        create_adj(bombs); // Create the adjacent list
        print_adj(); // Print the adjacent list information

        int ans = 0;
        detonated.assign(n, 0);
        for(int i = 0; i < n; i++){
            if(!detonated[i]){
                MaxBomb = 0;
                dfs(i); // Call the DFS function to calculate the number of bombs in the detonation range
                ans = max(ans, MaxBomb);
            }
            detonated.assign(n, 0);
        }
        cout << ans << endl;
        return ans;
    }
};