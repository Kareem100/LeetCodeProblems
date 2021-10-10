/*
Problem Title:  Maximum Score Words Formed by Letters
Problem URL:    https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/

Description:    Given a list of words, list of  single letters (might be repeating) and score of every character.
                Return the maximum score of any valid set of words 
                formed by using the given letters (words[i] cannot be used two or more times).
                It is not necessary to use all characters in letters and each letter can only be used once. 
                Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

Difficulty: Hard
Language: C++
Category: Algorithms
*/

class Solution {

private:
    int getmax(vector<string>& words, vector<int>& freq, vector<int>& score, int i) {
         
        if(i==words.size())
             return 0;
         
         int ansN = getmax(words, freq, score, i+1);
         
         int scoreAcc = 0;
         string str = words[i];
         bool flag = true;
         
         for(int i=0; i < str.size(); ++i)
         {
             freq[str[i]-'a']--;
             scoreAcc += score[str[i]-'a'];
             
             if(freq[str[i]-'a'] < 0)
                 flag = false;
         }
         
         int ansY = 0;
         if(flag)
             ansY = scoreAcc + getmax(words, freq, score, i+1); 
         
         for(int i=0; i < str.size(); ++i)
             freq[str[i]-'a']++;
         
         return max(ansN, ansY);
     }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        
        for(int i=0; i < letters.size(); ++i)
           freq[letters[i]-'a']++;
        
        return getmax(words, freq, score, 0);
    }
    
};