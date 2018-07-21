/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// Iteration
// Time O(n+m)  Space O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *rt = NULL, *cur = NULL;
        while (l1 || l2) {
            if (NULL == l1) {
                if (NULL == cur) {
                    cur = l2;
                    rt = cur;
                } else {
                    cur->next = l2;
                }
                break;
            }
            if (NULL == l2) {
                if (NULL == cur) {
                    cur = l1;
                    rt = cur;
                } else {
                    cur->next = l1;
                }
                break;
            }
            if (l1->val < l2->val) {
                if (NULL == cur) {
                    cur = l1;
                    rt = cur;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            } else {
                if (NULL == cur) {
                    cur = l2;
                    rt = cur;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        return rt;
    }
};
