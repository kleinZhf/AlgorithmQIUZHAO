/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *rlist = reverseList(slow->next);
        ListNode *list = head;

        while (list && rlist) {
            if (list->val != rlist->val) {
                return false;
            }
            list = list->next;
            rlist = rlist->next;
        }

        slow->next = reverseList(rlist);

        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *newhead = nullptr;

        while (head) {
            ListNode *tmp = head->next;
            head->next = newhead;
            newhead = head;
            head = tmp;
        }

        return newhead;
    }
};
// @lc code=end

