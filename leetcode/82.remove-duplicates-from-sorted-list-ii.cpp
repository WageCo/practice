/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        std::vector<ListNode *> visited;
        ListNode *dynamicNode = new ListNode(0);
        ListNode *tail = dynamicNode;
        while (head) {
            if (head->next && head->next->val == head->val) {
                visited.push_back(head); // mark
                int val = head->val;     // duplicate val
                head = head->next;
                auto p = head;
                for (; p && p->val == val; p = p->next) {
                    visited.push_back(p); // mark
                }
                head = p;
            } else {
                tail->next = head;
                tail = tail->next;
                head = head->next;
            }
        }
        tail->next = nullptr;
        std::for_each(visited.cbegin(), visited.cend(),
                      [](auto it) { delete it; });
        tail = dynamicNode;
        dynamicNode = dynamicNode->next;
        delete tail;
        return dynamicNode;
    }
};
// @lc code=end

