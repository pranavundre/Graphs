class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    int numEnclaves(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size(), n = grid[0].size(), count = 0;
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) q.push({i, 0});
            if(grid[i][n-1] == 1) q.push({i, n-1});
        }
        for(int i = 1; i < n-1; i++){
            if(grid[0][i] == 1) q.push({0, i});
            if(grid[m-1][i] == 1) q.push({m-1, i});
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(grid[r][c] != 1) continue;
            grid[r][c] = 0;
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc] == 1) q.push({nr, nc});
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1) count++;
        return count;
    }
};
