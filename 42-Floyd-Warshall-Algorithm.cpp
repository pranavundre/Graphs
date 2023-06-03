class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < n; j++)
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            
	    for(int a = 0; a < n; a++)
    	    for(int i = 0; i < n; i++)
    	        for(int j = 0; j < n; j++)
    	            matrix[i][j] = min(matrix[i][j], matrix[i][a] + matrix[a][j]);
	    
	    for(int i = 0; i < n; i++)
	        for(int j = 0; j < n; j++)
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	}
};
