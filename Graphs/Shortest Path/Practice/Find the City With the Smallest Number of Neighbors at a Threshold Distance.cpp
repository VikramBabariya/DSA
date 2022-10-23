int findTheCity(int n, vector<vector<int>>& edges, int th) {
    vector<vector<int>> matrix(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++) matrix[i][i] = 0;
    for(auto edge: edges){
        matrix[edge[0]][edge[1]] = edge[2];
        matrix[edge[1]][edge[0]] = edge[2];
    }

    for(int via = 0; via < n; via++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    int minCnt = 1e9, ans = -1;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(matrix[i][j] <= th) cnt++;
        }
        if(cnt <= minCnt){
            minCnt = cnt;
            ans = i;
        }
    }
    return ans;
}
