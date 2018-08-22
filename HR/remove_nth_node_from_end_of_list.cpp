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
    // One pass
    // Time O(n)  Space O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *l, *r = l = head;
        while (--n) {
            r = r->next;
        }
        ListNode *prev = NULL;
        while (r->next != NULL) {
            r = r->next;
            prev = l;
            l = l->next;
        }
        if (prev == NULL) {
            return l->next;
        } else {
            prev->next = l->next;
            return head;
        }

    }
};
