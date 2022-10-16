

void bfs(int sr, int sc, vector<vector<int>>& image, int n, int m, int oldColor, int newColor){
    queue<pair<int, int>> cells;
    cells.push({sr, sc});
    image[sr][sc] = newColor;

    while(cells.size()){
        auto pr = cells.front();
        cells.pop();
        int i = pr.first, j = pr.second;

        //general code
        if(j > 0 && image[i][j-1] == oldColor){
            cells.push({i, j-1});
            image[i][j-1] = newColor;
        }
        if(j < m-1 && image[i][j+1] == oldColor){
            cells.push({i, j+1});
            image[i][j+1] = newColor;
        }
        if(i > 0 && image[i-1][j] == oldColor){
            cells.push({i-1, j});
            image[i-1][j] = newColor;
        }
        if(i < n-1 && image[i+1][j] == oldColor){
            cells.push({i+1, j});
            image[i+1][j] = newColor;
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc], n = image.size(), m = image[0].size();

    if(oldColor != newColor)
        bfs(sr, sc, image, n, m, oldColor, newColor);

    return image;
}
};
