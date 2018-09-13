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
    // Reverse Half
    // Time O(n)  Space O(1)
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode *fast = head, *slow = head;
        while (NULL != fast && NULL != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *tail = NULL;
        while (slow) {
            //cout << slow->val << endl;
            ListNode *tmp = slow->next;
            slow->next = tail;
            tail = slow;
            slow = tmp;
        }
        fast = head;
        while (tail && fast) {
            cout << tail->val << " " << fast->val << endl;
            ListNode *tmp = tail->next;
            tail->next = fast->next;
            fast->next = tail;
            fast = tail->next;
            tail = tmp;
        }
        fast->next = NULL;
    }
};
