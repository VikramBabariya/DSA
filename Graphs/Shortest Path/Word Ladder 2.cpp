vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {    
    int wordLen = beginWord.size(), minLen = 1000, level = 0;
    vector<vector<string>> ans;    
    unordered_set<string> remainWords(wordList.begin(), wordList.end());
    vector<string> toBeRemove;
    queue<vector<string>> ladder;
    vector<string> sequence; sequence.push_back(beginWord);
    ladder.push(sequence);
    toBeRemove.push_back(beginWord);

    while(ladder.size()){
        vector<string> sequence = ladder.front();
        int step = sequence.size();
        string word = sequence[step-1];
        ladder.pop();

        if(step > level){
            level++;
            int s = toBeRemove.size();
            for(int i = s-1; i >= 0; i--){
                remainWords.erase(toBeRemove[i]);
                toBeRemove.pop_back();
            }
        }

        if(word == endWord){
            if(step <= minLen){
                ans.push_back(sequence);
                minLen = step;
                continue;
            }
            else break;
        }

        //exploting all possible options
        vector<string> toBeRemove;
        for(int i = 0; i < wordLen; i++){
            char temp = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;

                if(remainWords.find(word) != remainWords.end()){
                    sequence.push_back(word);
                    ladder.push(sequence);
                    sequence.pop_back();
                    toBeRemove.push_back(word);
                }
            }
            word[i] = temp;
        }
    }
    return ans;
}
