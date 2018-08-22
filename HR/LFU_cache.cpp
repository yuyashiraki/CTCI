/*
 * (Parent 1)--(Node a)--(Node b)--(Node c)
 *     |
 * (Parent 2)--(Node d)--(Node e)
 *     |
 * (Parent 3)
 *     |
 * (Parent 4)--(Node f)
 *
 * Map { A:&(Node a), B:&(Node b), C:&(Node c), ... }
 */
class Parent;
class Node {
public:
    list<Parent*>::iterator parent;
    int key, val;
    Node(int k, int v) {
        key = k;
        val = v;
    }
};
class Parent {
public:
    list<Node*> lst;
};
class LFUCache {
public:
    unordered_map<int, list<Node*>::iterator> MP;
    list<Parent*> LST;
    int CAP;
    int num;
    LFUCache(int capacity) {
        CAP = capacity;
        num = 0;
        LST.push_back(new Parent());
    }
    int get(int key) {
        if (!MP.count(key)) return -1;
        list<Node*>::iterator nitr = MP[key];
        Node *n = *nitr;
        list<Parent*>::iterator pitr = n->parent;
        Parent *p = *pitr;
        list<Parent*>::iterator nextpitr = pitr;
        if (LST.end() == ++nextpitr) {
            // Add new parent if not exist
            LST.push_back(new Parent());
        }
        Parent *nextp = *(++pitr);

        // Delete node from current parent
        p->lst.erase(nitr);
        nextp->lst.push_back(n);
        n->parent = pitr;
        MP[key] = nextp->lst.end();
        MP[key]--;
        return n->val;
    }
    void put(int key, int value) {
        if (MP.count(key)) {
            Node *n = *(MP[key]);
            n->val = value;
            get(key);
        } else {
            Node *n = new Node(key, value);
            if (CAP == 0) return;
            if (num == CAP) {
                for (auto itr = LST.begin(); itr != LST.end(); ++itr) {
                    if ((*itr)->lst.empty()) {
                        continue;
                    }
                    Node *deln = *((*itr)->lst.begin());
                    MP.erase(deln->key);
                    delete deln;
                    (*itr)->lst.pop_front();
                    break;
                }
                num--;
            }
            list<Parent*>::iterator pitr = LST.begin();
            Parent *p = *pitr;
            n->parent = pitr;
            p->lst.push_back(n);
            MP[key] = p->lst.end();
            MP[key]--;
            num++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
