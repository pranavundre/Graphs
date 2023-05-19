// Leetcode Solution
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '2';
        if(r!=0 && grid[r-1][c]=='1') dfs(r-1, c, grid);
        if(r!=grid.size()-1 && grid[r+1][c]=='1') dfs(r+1, c, grid);
        if(c!=0 && grid[r][c-1]=='1') dfs(r, c-1, grid);
        if(c!=grid[0].size()-1 && grid[r][c+1]=='1') dfs(r, c+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    res++;
                    dfs(i, j, grid);
                }
        return res;
    }
};

// GFG Solution
class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '2';
        if(r!=0 && c!=0 && grid[r-1][c-1]=='1') dfs(r-1, c-1, grid);
        if(r!=0 && c!=grid[0].size()-1 && grid[r-1][c+1]=='1') dfs(r-1, c+1, grid);
        if(r!=grid.size()-1 && c!=0 && grid[r+1][c-1]=='1') dfs(r+1, c-1, grid);
        if(r!=grid.size()-1 && c!=grid[0].size()-1 && grid[r+1][c+1]=='1') dfs(r+1, c+1, grid);
        if(r!=0 && grid[r-1][c]=='1') dfs(r-1, c, grid);
        if(r!=grid.size()-1 && grid[r+1][c]=='1') dfs(r+1, c, grid);
        if(c!=0 && grid[r][c-1]=='1') dfs(r, c-1, grid);
        if(c!=grid[0].size()-1 && grid[r][c+1]=='1') dfs(r, c+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    res++;
                    dfs(i, j, grid);
                }
        return res;
    }
};
