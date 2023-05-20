class Solution {
  public:
    bool checkDFS(vector<int> adj[], vector<int>& vis, int &index){
        int visCount = 0;
        for(int i : adj[index]) if(vis[i] != 0) visCount++;
        if(visCount > 1) return true;
        for(int i : adj[index])
            if(vis[i]++ == 0 && checkDFS(adj, vis, i)) return true;
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
            if(vis[i]++ == 0 && checkDFS(adj, vis, i)) return true;
        return false;
    }
};
