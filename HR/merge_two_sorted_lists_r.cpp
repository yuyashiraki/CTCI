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
    // Time O(n)  Space O(1)
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *cur = head;
        while (l1 || l2) {
            if (NULL == l1) {
                if (NULL == cur) {
                    head = cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            } else if (NULL == l2 || l1->val < l2->val) {
                if (NULL == cur) {
                    head = cur = l1;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } else {
                if (NULL == cur) {
                    head = cur = l2;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        return head;
    }
};
