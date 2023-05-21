class Solution {
public:
    bool check(vector<vector<int>> &graph, vector<int> &color, int index){
        queue<int> q;
        q.push(index);
        color[index] = 0;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i : graph[temp])
                if(color[i] == -1){
                    q.push(i);
                    color[i] = !color[temp];
                }
                else if(color[temp] == color[i]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) if(color[i] == -1) if(!check(graph, color, i)) return false;
        return true;
    }
};
