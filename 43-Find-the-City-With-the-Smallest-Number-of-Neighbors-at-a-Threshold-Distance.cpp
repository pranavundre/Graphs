class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));
        
        for(auto vec: edges) matrix[vec[0]][vec[1]] = matrix[vec[1]][vec[0]] = vec[2];
        
        for(int i = 0; i < n; i++) matrix[i][i] = 0;

        for(int a = 0; a < n; a++)
    	    for(int i = 0; i < n; i++)
    	        for(int j = 0; j < n; j++)
    	            matrix[i][j] = min(matrix[i][j], matrix[i][a] + matrix[a][j]);

        int minCity = INT_MAX, res;
        for(int i = 0; i < n; i++){
            int neighb = 0;
            for(int j = 0; j < n; j++) if(matrix[i][j] <= dt) neighb++;
            if(neighb <= minCity) {
                minCity = neighb;
                res = i;
            }
        }

        return res;
    }
};
