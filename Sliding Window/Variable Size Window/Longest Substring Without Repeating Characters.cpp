int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, n = s.size();
    int maxi = 0;
    map<char, int> fr;

    while(j < n){
        fr[s[j]]++; 

        if(fr.size() == (j-i+1)){
            maxi = max(maxi, j-i+1);
            j++;
        }
        else if(fr.size() < (j-i+1)){
            while(fr.size() < (j-i+1)){
                fr[s[i]]--;
                if(fr[s[i]] == 0) fr.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
}
