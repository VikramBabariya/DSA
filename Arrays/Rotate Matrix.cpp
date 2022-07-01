
    
	void transpose(vector<vector<int>>& matrix, int m, int n){
			for(int i = 0; i < m; i++){
					for(int j = i; j < n; j++){ // note j is starting from i , because we dont want to alter above rows.
							int temp = matrix[i][j];
							matrix[i][j] = matrix[j][i];
							matrix[j][i] = temp;
					}
			}
	}

	void rev(vector<vector<int>>& matrix, int m, int n){
			for(int i = 0; i < m; i++){
					reverse(matrix[i].begin(), matrix[i].end());
			}
	}


	void rotate(vector<vector<int>>& matrix) {
			transpose(matrix, matrix.size(), matrix[0].size());
			rev(matrix, matrix.size(), matrix[0].size());
	}
