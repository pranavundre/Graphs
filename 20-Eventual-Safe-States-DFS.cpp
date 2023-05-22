class Solution {
public:
    bool checkDFS(vector<int> adj[], vector<int> &vis, vector<int> &safeNodes, int index){
        vis[index] = 1;
        bool res;
        for(int i : adj[index]){
            if(safeNodes[i] == 0 && vis[i] == 1) return false; 
            else if(safeNodes[i] == 1 || checkDFS(adj, vis, safeNodes, i)){
                res = true;
                safeNodes[i] = 1;
            }
            else return false;
        }
        return res;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> safeNodes(V, 0), vis(V, 0), res;
        for(int i = 0; i < V; i++) if(adj[i].empty()) safeNodes[i] = vis[i] = 1;
        for(int i = 0; i < V; i++){
            if(safeNodes[i] == 1) res.emplace_back(i);
            if(vis[i] == 0 && checkDFS(adj, vis, safeNodes, i)){
                safeNodes[i] = 1;
                res.emplace_back(i);
            }
        }
        return res;
    }
};
