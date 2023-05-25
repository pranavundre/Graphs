class Solution {
    public:
    vector<int> dir{0, 1, 0, -1, 0};
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vis[source.first][source.second] = 1;
        
        queue<pair<int, int>> q;
        q.push(source);
        int dist = -1;
        
        while(!q.empty()){
            int size = q.size();
            dist++;
            while(size--){
                auto p = q.front();
                q.pop();
                
                if(p == destination) return dist;
                int r = p.first;
                int c = p.second;
                
                for(int i = 0; i < 4; i++){
                    int nr = r + dir[i];
                    int nc = c + dir[i+1];
                    
                    if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] == 1 && vis[nr][nc]++ == 0){
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        return -1;
    }
};
