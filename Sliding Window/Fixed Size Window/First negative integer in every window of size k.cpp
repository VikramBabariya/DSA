vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k) {
    int i = 0, j = 0;
    queue<long long> negs;
    vector<long long> ans;

    while(j < n){
        if(arr[j] < 0) negs.push(arr[j]);
        if(j-i+1 < k) j++;
        else{
            //cout<<negs.size()<<" ";
            if(negs.size() == 0) ans.push_back(0);
            else ans.push_back(negs.front());

            if(arr[i] < 0) negs.pop();
            i++; j++;
        }
    }
    return ans;
}
