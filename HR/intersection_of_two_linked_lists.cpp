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
    // using two pointers (preprocess first)
    // Time O(m + n)  Space O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *rootA = headA, *rootB = headB;
        int heightA = 0, heightB = 0;
        while (rootA->next != NULL) {
            rootA = rootA->next;
            heightA++;
        }
        while (rootB->next != NULL) {
            rootB = rootB->next;
            heightB++;
        }
        if (rootA != rootB) {
            return NULL;
        }
        if (heightA > heightB) {
            while (heightA > heightB) {
                headA = headA->next;
                heightA--;
            }
        } else {
            while (heightB > heightA) {
                headB = headB->next;
                heightB--;
            }
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }

    // Using two pointers (no preprocess)
    // Time O(m + n)  Space O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *A = headA; ListNode *B = headB;
        while (A != B) {
            A = A == NULL ? headB : A->next;
            B = B == NULL ? headA : B->next;
        }
        return A;
    }
};
