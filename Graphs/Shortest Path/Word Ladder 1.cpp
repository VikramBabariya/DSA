int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int wordLen = beginWord.size();
    unordered_set<string> remainWords(wordList.begin(), wordList.end());
    queue<pair<string, int>> ladder;
    ladder.push({beginWord, 1});
    remainWords.erase(beginWord);

    while(ladder.size()){
        string word = ladder.front().first;
        int step = ladder.front().second;
        ladder.pop();

        if(word == endWord) return step;

        //exploting all possible options
        for(int i = 0; i < wordLen; i++){
            char temp = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;

                if(remainWords.find(word) != remainWords.end()){
                    ladder.push({word, step+1});
                    remainWords.erase(word);
                }
            }
            word[i] = temp;
        }
    }
    return 0;
}
