class Solution {
public:
    void bfsFlood(vector<vector<int>>& image, int r, int c, int original, int& color){
        queue<pair<int, int>> q;
        q.emplace(make_pair(r, c));
        while(!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();
            image[r][c] = color;
            if(r > 0 && image[r-1][c] == original) q.emplace(make_pair(r-1, c));
            if(r < image.size()-1 && image[r+1][c] == original) q.emplace(make_pair(r+1, c));
            if(c > 0 && image[r][c-1] == original) q.emplace(make_pair(r, c-1));
            if(c < image[0].size()-1 && image[r][c+1] == original) q.emplace(make_pair(r, c+1));
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        bfsFlood(image, sr, sc, image[sr][sc], color);
        return image;
    }
};
