vector<vector<int>> merge(vector<vector<int>>& inters) {
    vector<vector<int>> ans;
    int n = inters.size();

    sort(inters.begin(), inters.end());

    int low = inters[0][0] , high = inters[0][1];
    for(int i = 1; i < n; i++){
        if(inters[i][0] <= high){
            high = max(high, inters[i][1]);
        }else{
            vector<int> temp(2, 0);
            temp[0] = low; temp[1] = high;
            ans.push_back(temp);
            low = inters[i][0]; high = inters[i][1];   
        }
    }
    vector<int> temp(2, 0);
    temp[0] = low; temp[1] = high;
    ans.push_back(temp);
    return ans;
}
