vector<int> findAnagrams(string s, string p) {
    int n = s.size(), i = 0, j = 0, k = p.size();
    vector<int> ans;
    map<char, int> fr;
    for(int i = 0; i < k; i++) fr[p[i]]++;
    int cnt = fr.size(); // to reduce map traversal

    while(j < n){
        if(fr.find(s[j]) != fr.end()){
            fr[s[j]]--;
            if(fr[s[j]] == 0) cnt--; // one char frequency matched
        }

        if(j-i+1 < k) j++;
        else{
            if(cnt == 0) ans.push_back(i); // all char freq matched
            if(fr.find(s[i]) != fr.end()){
                fr[s[i]]++;
                if(fr[s[i]] == 1) cnt++; // need to match one more char
            }
            i++; j++;
        }
    }
    return ans;
}
