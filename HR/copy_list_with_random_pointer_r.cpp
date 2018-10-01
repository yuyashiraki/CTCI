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
        if (head == NULL) return NULL;
        RandomListNode *rt;
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next) {
            RandomListNode *cp = new RandomListNode(cur->label);
            cp->next = cur->next;
            cur->next = cp;
            cur = cp;
        }
        rt = head->next;
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next->next) {
            cur->next->random = cur->random ? cur->random->next : NULL;
        }
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next) {
            RandomListNode *cp = cur->next;
            cur->next = cp->next;
            cp->next = cp->next ? cp->next->next : NULL;
        }
        return rt;
    }

    // using Hash Table
    // Time O(n)  Space O(1)
    unordered_map<RandomListNode*, RandomListNode*> MP;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        RandomListNode *rt = NULL, *prv = NULL;
        for (RandomListNode *cur = head; cur != NULL; cur = cur->next) {
            if (0 == MP.count(cur)) MP[cur] = new RandomListNode(cur->label);
            RandomListNode *cp = MP[cur];
            if (rt == NULL) rt = cp;
            if (prv) prv->next = cp;
            prv = cp;
            if (cur->random != NULL && 0 == MP.count(cur->random)) MP[cur->random] = new RandomListNode(cur->random->label);
            RandomListNode *randomcp = cur->random ? MP[cur->random] : NULL;
            cp->random = randomcp;
        }
        prv->next = NULL;
        return rt;
    }
};
