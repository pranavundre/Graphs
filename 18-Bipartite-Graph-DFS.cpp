class Solution {
public:
    bool checkDFS(vector<vector<int>> &graph, vector<int> &color, int index, int lvl){
        if(color[index] != -1 && color[index] != lvl%2) return false;
        color[index] = lvl%2;
        for(int i : graph[index]){
            if(color[i] == -1 && !checkDFS(graph, color, i, lvl+1)) return false;
            else if(color[i] == color[index]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) if(color[i] == -1) if(!checkDFS(graph, color, i, 0)) return false;
        return true;
    }
};
