string minWindow(string s, string t) {
    int i = 0, j = 0, n = s.size();
    int mini = INT_MAX, mi, mj;
    map<char, int> fr;
    for(auto &c: t) fr[c]++;
    int cnt = fr.size();

    while(j < n){
        if(fr.find(s[j]) != fr.end()){
            fr[s[j]]--;
            if(fr[s[j]] == 0) cnt--;
        }

        while(cnt == 0){
            if(j-i+1 < mini){
                mini = j-i+1;
                mi = i; mj = j;
            }
            if(fr.find(s[i]) != fr.end()){
                fr[s[i]]++;
                if(fr[s[i]] == 1) cnt++;
            }
            i++;
        }
        j++;
    }
    if(mini == INT_MAX) return "";
    return s.substr(mi, mj-mi+1);
}
