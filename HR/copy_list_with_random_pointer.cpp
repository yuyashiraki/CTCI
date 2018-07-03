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
    // using map
    // Time O(n)  Space O(1)
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode *copyRandomList(RandomListNode *head) {
        /*
         Deep Copy: create object that has same data
         Shallow Copy: create pointer that point to the same object
        */
        if (head == NULL) return NULL;
        if (mp[head] != NULL) return mp[head];
        RandomListNode *rt = new RandomListNode(head->label);
        mp[head] = rt;
        rt->random = copyRandomList(head->random);
        rt->next = copyRandomList(head->next);
        return rt;
    }

    // without using map
    // Time O(3n)  Space O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (NULL == head) return NULL;
        RandomListNode *l1, *l2;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
        }

        RandomListNode *newHead = head->next;
        for (l1 = head; l1 != NULL; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next;
        }

        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->next;
            l1->next = l2->next;
            if (l2->next != NULL) l2->next = l2->next->next;
        }
        return newHead;
    }
};
