int longestKSubstr(string s, int k) {
    int i = 0, j = 0, n = s.size();
    int maxi = -1;
    map<char, int> fr;

    while(j < n){
        fr[s[j]]++; 

        if(fr.size() < k) j++;
        else if(fr.size() == k){
            maxi = max(maxi, j-i+1);
            j++;
        }
        else{
            while(fr.size() > k){
                fr[s[i]]--;
                if(fr[s[i]] == 0) fr.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}
