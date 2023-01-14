class Solution {
public:
    map<string,int> mapping;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string> sequence)
    {
        if(word==b)
        {
            reverse(sequence.begin(),sequence.end());
            ans.push_back(sequence);
            reverse(sequence.begin(),sequence.end());
            return;
        }
        int count = mapping[word];
        for(int i=0;i<word.size();++i)
        {
            char original = word[i];
            for(char ch='a';ch<='z';++ch)
            {
                word[i]=ch;
                if(mapping.find(word)!=mapping.end() && mapping[word]+1 == count)
                {
                    sequence.push_back(word);
                    dfs(word,sequence);
                    sequence.pop_back();
                }
            }
            word[i]=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) 
    {
        unordered_set<string> available(wordList.begin(),wordList.end());
        queue<string> nodes;
        int sizee = beginWord.size();
        b=beginWord;
        nodes.push(beginWord);
        mapping[beginWord]=1;
        available.erase(beginWord);
        while(!nodes.empty())
        {
            string word = nodes.front();
            nodes.pop();
            int count = mapping[word];
            if(word==endWord)
                break;
            for(int i=0;i<sizee;++i)
            {
                char original = word[i];
                for(char ch='a';ch<='z';++ch)
                {
                    word[i]=ch;
                    if(available.find(word)!=available.end())
                    {
                        nodes.push(word);
                        mapping[word]=count+1;
                        available.erase(word);
                    }
                }
                word[i]=original;
            }
        }
        if(mapping.find(endWord)!=mapping.end())
        {
            vector<string> sequence;
            sequence.push_back(endWord);
            dfs(endWord,sequence);
        }
        return ans;
    }
};