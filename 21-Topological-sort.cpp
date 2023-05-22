class Solution{
	public:
	void checkDFS(vector<int> adj[], vector<int> &vis, stack<int> &stk, int index){
	    vis[index] = 1;
	    for(int i : adj[index]) if(vis[i] == 0) checkDFS(adj, vis, stk, i);
	    stk.push(index);
	}
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> vis(V, 0), res;
	    stack<int> stk;
	    for(int i = 0; i < V; i++) if(vis[i] == 0) checkDFS(adj, vis, stk, i);
	    while(!stk.empty()){
	        res.emplace_back(stk.top());
	        stk.pop();
	    }
	    return res;
	}
};
