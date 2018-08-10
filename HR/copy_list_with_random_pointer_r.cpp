/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    // three pass
    // Time O(n)  Space O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) return NULL;
        RandomListNode *cur = head, *tmp;
        while (NULL != cur) {
            tmp = cur->next;
            cur->next = new RandomListNode(cur->label);
            cur->next->next = tmp;
            cur = tmp;
        }
        //cout << "DEBUG" << endl;
        cur = head;
        while (NULL != cur) {
            if (NULL != cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        //cout << "DEBUG" << endl;
        RandomListNode *ans = head->next;
        cur = head;
        while (NULL != cur) {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = cur->next;
            if (NULL != cur) tmp->next = cur->next;
        }
        return ans;
    }
};
