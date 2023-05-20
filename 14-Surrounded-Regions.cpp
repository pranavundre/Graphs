class Solution {
public:
    vector<int> dir = {0, -1, 0, 1, 0};
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][n-1] == 'O') q.push({i, n-1});
        }
        for(int i = 1; i < n-1; i++){
            if(board[0][i] == 'O') q.push({0, i});
            if(board[m-1][i] == 'O') q.push({m-1, i});
        }
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            board[r][c] = 'o';
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc] == 'O') q.push({nr, nc});
            }
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(board[i][j] == 'o') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
};
