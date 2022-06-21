class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int low = (int)-1e9, high = (int)1e9;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            int cnt = 0;
            for(int i = 0; i < n; i++){
               cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin(); 
            }
            
            if(cnt < k) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
