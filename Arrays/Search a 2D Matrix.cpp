//leetcode problem 

//sol1: BST approach , TC:O(n + m)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m-1;

    while(i < n && j > -1) {
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] < target) i++;
        else j--;
    }
    return false;
}

//sol2 Bianary Search on single row TC:O(n + logm)
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(), m = mat[0].size();
    for(int i = 0; i < n; i++){
        if(target <= mat[i][m-1]){
            return binary_search(mat[i].begin(), mat[i].end(), target);
        }
    }
    return false;
}

//sol3: Binary Search on entire matrix TC:O(log(n*m)) , Most Optimal
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
		// if matrix have 0 rows or 0 colums
        if(n == 0 || m == 0)
            return false;
        
		// treating matrix as array just taking care of endices
		// [0..n*m]
        int start = 0, end = m*n - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
			// a[x] : matrix[x / m][x % m] formulae
            int ind = matrix[mid/m][mid%m];
            if (target == ind)
                return true;
			// left half
            else if(target < ind)
                end = mid - 1;
            else
			// right half
                start = mid + 1;       
        }
        return false;
    }
	// for github repository link go to my profile.
};




