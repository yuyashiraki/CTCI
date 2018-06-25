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
    // Using slow&fast pointers, Time O(n) Space O(1)
    bool isPalindrome(ListNode* head)
    {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);
        fast = head;
        while (fast && slow) {
            if (fast->val != slow->val) {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode *reverse(ListNode* head)
    {
        ListNode *prev = NULL, *next;
        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
