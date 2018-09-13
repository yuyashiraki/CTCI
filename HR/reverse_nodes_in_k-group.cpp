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
    ListNode *reverse(ListNode *head, ListNode *next, int k) {
        while (k--) {
            ListNode *tmp = head->next;
            head->next = next;
            next = head;
            head = tmp;
        }
        return next;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2) return head;
        ListNode *root = new ListNode(0);
        ListNode *cur = root;
        root->next = head;
        for (ListNode *cur = root; cur != NULL;) {
            int cnt = k;
            ListNode *tmp = cur;
            while (cnt--) {
                if (NULL == tmp->next) return root->next;
                tmp = tmp->next;
            }
            ListNode *next = cur->next;
            cur->next = reverse(next, tmp->next, k);
            cur = next;
        }
        return root->next;
    }
};
