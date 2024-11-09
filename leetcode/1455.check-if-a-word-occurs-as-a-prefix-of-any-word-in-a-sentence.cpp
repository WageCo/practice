/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */
#include <bits/stdc++.h>
using std::string;
using std::vector;
using std::istringstream;
// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word;
        int count = 0;
        istringstream ss(sentence); // istringstream 分割
        while (ss >> word)
        {
            ++count;
            int pos = word.find(searchWord);
            if (pos != word.npos && pos == 0)
                return count;
        }
        return -1;
    }
};
// @lc code=end

