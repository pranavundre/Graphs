class Solution{
public:
	int orangesRotting(vector<vector<int>> &grid){
		bool fruits = false;
		for (auto a : grid)
			for (int x : a)
				if (x != 0)
					fruits = true;

		if(!fruits) return 0;
		int res = -1;
		queue<pair<int, int>> q;

		for (int i = 0; i < grid.size(); i++)
			for (int j = 0; j < grid[0].size(); j++)
				if (grid[i][j] == 2)
					q.push({i, j});

		while (!q.empty()){
			res++;
			int size = q.size();
			while (size--){
				auto p = q.front();
				q.pop();
				int r = p.first;
				int c = p.second;
				if (r > 0 && grid[r - 1][c] == 1){
					grid[r - 1][c] = 2;
					q.push({r - 1, c});
				}
				if (r < grid.size() - 1 && grid[r + 1][c] == 1){
					grid[r + 1][c] = 2;
					q.push({r + 1, c});
				}
				if (c > 0 && grid[r][c - 1] == 1){
					grid[r][c - 1] = 2;
					q.push({r, c - 1});
				}
				if (c < grid[0].size() - 1 && grid[r][c + 1] == 1){
					grid[r][c + 1] = 2;
					q.push({r, c + 1});
				}
			}
		}

		for (auto a : grid)
			for (int x : a)
				if (x == 1)
					return -1;

		return res;
	}
};
