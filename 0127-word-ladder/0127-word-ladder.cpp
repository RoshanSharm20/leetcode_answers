class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<pair<string,int>> nodes;
        nodes.push({beginWord,1});
        unordered_set<string> available({wordList.begin(),wordList.end()});
        available.erase(beginWord);
        while(!nodes.empty())
        {
            auto word = nodes.front().first;
            auto count = nodes.front().second;
            nodes.pop();
            if(word==endWord)
                return count;
            for(int i=0;i<word.size();++i)
            {
                char original = word[i];
                for(char j='a';j<='z';++j)
                {
                    word[i]=j;
                    if(available.find(word)!=available.end())
                    {
                        nodes.push({word,count+1});
                        available.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};