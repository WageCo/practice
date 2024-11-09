/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */
#include <bits/stdc++.h>
using std::vector;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> v;
        for (auto i = head; i != nullptr; i = i->next) {
            v.emplace_back(i);
        }
        if (v.size() <= 2)
            return;
        ListNode *cur = nullptr;
        ListNode *q = head;
        bool odd = (v.size() & 0x01 == 1) ? true : false;
        for (auto i = v.crbegin(); i != v.crend(); ++i) {
            if (q == *i && odd) {
                cur->next = q; // odd 特殊情况跳出
                q->next = nullptr;
                break;
            }
            if (cur == nullptr) {
                cur = q;
            } else {
                cur->next = q;
                cur = q;
            }
            q = q->next;
            if (q == *i && !odd) {
                cur->next = q; //  even 特殊情况跳出
                q->next = nullptr;
                break;
            }
            cur->next = *i;
            cur = *i;
        }
    }
};
// @lc code=end

