/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *result = new ListNode(0);

        result->next = head;
        ListNode *pre = result, *slow = head, *fast = head;

        while (fast) {
            int c = 0;
            while (c < k && fast) {
                fast = fast->next;
                ++c;
            }
            if (c != k) break;

            ListNode *newhead = NULL;
            ListNode *tail = slow;

            while (slow != fast) {
                ListNode *tmp = slow->next;
                slow->next = newhead;
                newhead = slow;
                slow = tmp;
            }

            pre->next = newhead;
            pre = tail;
            tail->next = slow;

        }

        return result->next;
    }
};
// @lc code=end

