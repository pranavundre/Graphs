class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    void dfs(vector<vector<int>>& grid, int r, int c, int r0, int c0, string &str) {
        int m = grid.size(), n = grid[0].size();
        grid[r][c] = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i];
            int nc = c + dir[i + 1];
            if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1) {
                str += to_string(r0-nr) + to_string(c0-nc);
                dfs(grid, nr, nc, r0, c0, str);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<string> st;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    string str = "";
                    dfs(grid, i, j, i, j, str);
                    st.insert(str);
                }
        return st.size();
    }
};
