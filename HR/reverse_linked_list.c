/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// Recursive
// Time O(n)  Space O(n)
struct ListNode* recur(struct ListNode* head) {
    struct ListNode* rt;
    if (head->next) {
        rt = recur(head->next);
        head->next->next = head;
    } else {
        rt = head;
    }
    return rt;
}

struct ListNode* reverseList(struct ListNode* head) {
    if (NULL == head) return NULL;
    struct ListNode* rt = recur(head);
    head->next = NULL;
    return rt;
}

// Iterative
// Time O(n) Space O(1)
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    while (head) {
        struct ListNode *next = head->next;
        head->next = prev;
        prev = head;
        if (next) {
            head = next;
        } else {
            break;
        }
    }
    return head;
}
