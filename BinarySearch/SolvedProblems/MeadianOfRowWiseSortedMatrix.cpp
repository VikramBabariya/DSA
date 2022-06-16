int findMedian(vector<vector<int> > &mat) {
    
    int n = mat.size(), m = mat[0].size();
    int low = 1, high = (int)1e9;
    
    while(low <= high){
        int mid = (low + high)/2;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        
        if(cnt <= (n*m)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}
