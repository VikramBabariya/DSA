void shortest_distance(vector<vector<int>>&matrix){
    int n = matrix.size();

    for(int via = 0; via < n; via++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(matrix[i][i] < 0) cout<<"nagative weight cycle"<<endl;
    }
}
