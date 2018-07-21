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
    // Iterative
    // Time O(n)  Space O(n)
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) return head;
        ListNode *ans = NULL;
        stack<pair<ListNode*,ListNode*>> Stk;
        Stk.emplace(head, head->next);
        head->next = NULL;
        while (!Stk.empty()) {
            pair<ListNode*,ListNode*> pp = Stk.top(); Stk.pop();
            if (pp.second == NULL) {
                ans = pp.first;
            } else {
                Stk.emplace(pp.second, pp.second->next);
                pp.second->next = pp.first;
            }
        }
        return ans;
    }

    // Recursive
    // Time O(n)  Space O(n)
    ListNode *recur(ListNode *prev, ListNode *cur) {
        ListNode *ans;
        if (cur) {
            ans = recur(cur, cur->next);
            cur->next = prev;
        } else {
            ans = prev;
        }
        return ans;
    }
    ListNode* reverseList(ListNode* head) {
        if (NULL == head) return head;
        ListNode *ans = recur(head, head->next);
        head->next = NULL;
        return ans;
    }
};
