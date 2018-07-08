class LRUCache {
public:
    class Node {
    public:
        Node *prev, *next;
        int val;
        int key;
        Node(int x, int y) {
            key = x;
            val = y;
            prev = this;
            next = this;
        }
    };
    class DoubleLinkedList {
    public:
        int size = 0, capacity;
        Node *top, *bottom;
        unordered_map<int, Node*> hashtbl;
        DoubleLinkedList(int x) {
            cout << "capacity:" << x << endl;
            capacity = x;
            top = NULL; bottom = NULL;
        }
        void insertNode(int key, int value) {
            Node *cur;
            if (hashtbl.find(key) != hashtbl.end()) {
                // key exists
                cur = hashtbl[key];
                cur->val = value;
            } else {
                cur = new Node(key, value);
                hashtbl[key] = cur;
                if (!size) {
                    top = bottom = cur;
                }
                size++;
                if (capacity < size) {
                    // cout << "over capacity" << endl;
                    pop();
                }
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            if (top == cur) {
                top = cur->next;
            }
            if (bottom != cur) {
                bottom->next = cur;
                cur->prev = bottom;
                cur->next = cur;
            }
            bottom = cur;
        }
        void deleteNode(int key) {
            if (hashtbl.find(key) == hashtbl.end()) {
                return;
            }
            Node *cur = hashtbl[key];
            hashtbl.erase(hashtbl.find(key));
            size--;
            if (!size) {
                top = bottom = NULL;
            } else {
                if (top == cur) {
                    top = cur->next;
                    top->prev = top;
                }
                else if (bottom == cur) {
                    bottom = bottom->prev;
                    bottom->next = bottom;
                } else {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                }
            }
            delete cur;
        }
        void pop() {
            if (!top) return;
            deleteNode(top->key);
        }
        int get(int key) {
            if (hashtbl.find(key) != hashtbl.end()) {
                insertNode(key, hashtbl[key]->val);
                return hashtbl[key]->val;
            } else {
                return -1;
            }
        }
        void printNode() {
            Node *cur = top;
            while (cur != bottom) {
                cout << "\t" << cur->key << " " << cur->val;
                cur = cur->next;
            }
            if (cur) cout << "\t" << cur->key << " " << cur->val << endl;
        }
    };
    DoubleLinkedList *list;
    LRUCache(int capacity) {
        list = new DoubleLinkedList(capacity);
    }

    int get(int key) {
        //cout << "get: " << key << endl;
        int rt = list->get(key);
        //list->printNode();
        return rt;
    }

    void put(int key, int value) {
        //cout << "put: " << key << value << endl;
        list->insertNode(key, value);
        //list->printNode();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
