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
    // Compare one by one
    // Time O(kn) where n nodes, k lists  Space: O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int minx = INT_MAX, minxidx = -1;
        ListNode* rt = NULL;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *cur = lists[i];
            if (cur == NULL) continue;
            if (cur->val < minx) {
                minx = cur->val;
                minxidx = i;
                rt = cur;
            } else {
                continue;
            }
        }
        if (rt == NULL) return NULL;
        lists[minxidx] = rt->next;
        rt->next = mergeKLists(lists);
        return rt;
    }


    // Using Priority Queue
    // Time O(nlog(k))  Space O(k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        for (int i = 0; i < lists.size(); i++) {
            ListNode *tmp = lists[i];
            if (NULL == tmp) continue;
            q.emplace(tmp->val, tmp);
        }
        if (q.empty()) return NULL;
        ListNode *head, *cur;
        head = cur = new ListNode(INT_MAX);
        while (!q.empty()) {
            cur->next = q.top().second;
            q.pop();
            cur = cur->next;
            cout << cur->val << endl;
            if (NULL == cur->next) {
                continue;
            } else {
                q.emplace(cur->next->val, cur->next);
            }
        }
        return head->next;
    }


    // Divide and conquer
    // Time O(nlog(k))  Space O(1)
    ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
        if (NULL == l1 || NULL == l2) return l1 == NULL ? l2 : l1;
        //cout << l1->val << " " << l2->val << endl;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> q;
        q.emplace(l1->val, l1); q.emplace(l2->val, l2);
        ListNode *head, *cur = head = new ListNode(INT_MAX);
        while (!q.empty()) {
            cur->next = q.top().second;
            q.pop();
            cur = cur->next;
            //cout << cur->val << endl;
            if (NULL == cur->next) {
                continue;
            } else {
                q.emplace(cur->next->val, cur->next);
            }
        }
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i = 0;
        cout << lists.size() << endl;
        while (i < lists.size()) {
            auto i2 = i + 1;
            if (i2 == lists.size()) return lists[i];
            //cout << (*itr)->val << " " << (*itr2)->val << endl;
            ListNode *tmp = merge2Lists(lists[i], lists[i2]);
            lists.push_back(tmp);
            i += 2;
        }
        return NULL;
    }
};
