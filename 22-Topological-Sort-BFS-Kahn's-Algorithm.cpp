class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> indegree(V, 0), res;
        queue<int> q;
        for(int i = 0; i < V; i++) for(int it : adj[i]) indegree[it]++;
        for(int i = 0; i < V; i++) if(indegree[i] == 0) q.push(i);
	    while(!q.empty()){
	        int temp = q.front();
	        q.pop();
	        res.emplace_back(temp);
	        for(int i : adj[temp]){
	            indegree[i]--;
	            if(indegree[i] == 0) q.push(i);
	        }
	    }
	    return res;
	}
};
