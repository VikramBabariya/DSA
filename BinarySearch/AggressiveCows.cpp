
bool allocPossible(int bar, int st, vector<int> &books){
    int allocSt = 1, pages = 0;
    for(int i = 0; i < (int)books.size(); i++){
        if(books[i] > bar) return false;
        if(books[i] + pages > bar){
            allocSt++;
            pages = books[i];
        }else pages += books[i];
    }
    if(allocSt <= st) return true;
    return false;
}


int books(vector<int> &books, int st) {
    int n = books.size();
    if(st > n) return -1;
    
    int low = *min_element(books.begin(), books.end()), high = accumulate(books.begin(), books.end(), 0);
    int res = -1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(allocPossible(mid, st, books)){
            res = mid;
            high = mid-1;
        }else low = mid+1;
    }
    return res;
}
