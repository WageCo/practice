/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */
#include <bits/stdc++.h>
using std::string;
using std::vector;
// @lc code=start
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string words;
        int count = 0;
        int index = 0;
        int pos = sentence.find_first_of(' ', index);
        if (pos == sentence.npos) return -1;
        words = sentence.substr(index, pos);
        while(!words.empty()){
            ++count;
            int temp_pos = words.find(searchWord);
            if (temp_pos != words.npos && temp_pos == 0){
                return count;
            }
            if (pos == sentence.npos) break;    // 最后一个单词判断玩 需要跳出循环
            index = pos + 1;
            words.clear();
            if (index < sentence.size()){
                pos = sentence.find_first_of(' ', index);
                if (pos == sentence.npos){
                    words = sentence.substr(index, sentence.size() - index);
                }
                words = sentence.substr(index, pos - index);
            }
        }
        return -1;
    }
};
// @lc code=end

