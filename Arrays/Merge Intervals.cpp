vector<vector<int>> merge(vector<vector<int>>& inters) {
    vector<vector<int>> ans;
    int n = inters.size();

    sort(inters.begin(), inters.end());

    vector<int> tempInter = inters[0]; 
    for(int i = 1; i < n; i++){
    if(inters[i][0] <= tempInter[1]){
        tempInter[1] = max(tempInter[1], inters[i][1]);
    }else{
        ans.push_back(tempInter);
        tempInter = inters[i];   
    }
    }
    ans.push_back(tempInter);
    return ans;
}
