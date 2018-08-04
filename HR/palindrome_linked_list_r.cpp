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
    // Find middle, reverse from middle, traverse again
    // Time O(n)  Space O(1)
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) slow = slow->next;
        fast = reverse(slow);
        slow = head;
        while (fast && slow) {
            if (fast->val == slow->val) {
                fast = fast->next;
                slow = slow->next;
            } else {
                return false;
            }
        }
        return true;
    }
    ListNode *reverse(ListNode *cur) {
        ListNode *prev = NULL;
        while (cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
