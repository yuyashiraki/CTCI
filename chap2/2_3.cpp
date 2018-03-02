#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <iterator>
using namespace std;

class Node {
public:
    Node* next = NULL;
    int data;
    Node(int d)
    {
        data = d;
    }
    Node* appendToTail(int d) {
        Node* end = new Node(d);
        Node* n = this;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = end;
        return end;
    }
    Node* deleteNode(Node* head, int d) {
        Node* n = head;
        if (n->data == d) {
            return head->next;
        }
        while (n->next != NULL) {
            if (n->next->data == d) {
                Node *rm = n->next;
                n->next = n->next->next;
                delete rm;
                return head;
            }
            n = n->next;
        }
        return head;
    }
};

void remove(Node *middle)
{
    if (middle == NULL) return;
    middle->data = middle->next->data;
    Node *rm = middle->next;
    middle->next = middle->next->next;
    delete rm;
}

void print(Node* head)
{
    while (head != NULL) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *lst = NULL;
    int n, e;
    cin >> n;
    int size = n;
    Node *mdl = NULL;
    while (n--) {
        Node *cur;
        cin >> e;
        if (lst == NULL) {
            lst = cur = new Node(e);
        } else {
            cur = lst->appendToTail(e);
        }
        if ((n != 0) && (n != (size - 1)) && (n == size/2)) mdl = cur;
    }
    print(lst);
    remove(mdl);
    print(lst);
    return 0;
}
