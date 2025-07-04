class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue< pair<string,int>> q; //{string, sequence length}
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end()); //Will take entire vewctor and put into set
        st.erase(beginWord); //set is here to act as visited[], so for the same, we erase element which is visited

        int steps = 0;
        while(!q.empty())
        {
            string word = q.front().first;
            steps = q.front().second;
            q.pop();

            //important edgecase and return statement
            if(word == endWord)
            return steps;

            for(int i = 0; i<word.size(); i++)
            {
                char original = word[i];
                for(char ch = 'a'; ch<= 'z'; ch++)
                {
                    word[i] = ch;
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }
                word[i] = original; //make the word back to normal state
            }
        }
        return 0;
    }
};