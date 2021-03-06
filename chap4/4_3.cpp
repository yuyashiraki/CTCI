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


template <typename T>
class Node
{
    public:
    T data;
    Node<T> *left = NULL, *right = NULL;
    int pos;
    Node(T data, int pos)
    {
        this->data = data;
        this->pos = pos;
    }
};

Node<int> *createBST(vector<int> &arr, int start, int end)
{
    if (end <= start) {
        return NULL;
    }
    int mid = (start + end) / 2;
    Node<int> *n = new Node<int>(arr[mid], mid);
    n->left = createBST(arr, start, mid);
    n->right = createBST(arr, mid + 1, end);
    return n;
}

void dfs(Node<int> *r)
{
    if (!r) return;
    cout << r->data << endl;
    dfs(r->left);
    dfs(r->right);
}

vector<list<Node<int> *> *> lv;
void createLevelLinkedList(Node<int> *r, int level)
{
    if (!r) return;
    list<Node<int> *> *l;
    if (lv.size() == level) {
        l = new list<Node<int> *>;
        lv.push_back(l);
    } else {
        l = lv[level];
    }
    l->push_back(r);
    createLevelLinkedList(r->left, level + 1);
    createLevelLinkedList(r->right, level + 1);
}

int binarySearch(vector<int> &arr, int tgt)
{
    int l = 0, r = arr.size(), m = (l + r) / 2;
    while (l < r) {
        m = (l + r) / 2;
        if (tgt == arr[m]) return m;
        else if (tgt < arr[m]) r = m;
        else l = m + 1;
    }
    return -1;
}

int binarySearch(Node<int> *r, int tgt)
{
    if (!r) return -1;
    if (r->data == tgt) return r->pos;
    if (r->data > tgt) return binarySearch(r->left, tgt);
    if (r->data < tgt) return binarySearch(r->right, tgt);
}

int main()
{
    int data[] = {1,3,4,11,15,18,19,20,21};
    vector<int> arr(data, end(data));
    Node<int> *r = createBST(arr, 0, arr.size());
    cout << "1,3,4,11,15,18,19,20,21" << endl;
//    cout << binarySearch(r, 21) << endl;
    createLevelLinkedList(r, 0);
    for (int i = 0; i < lv.size(); i++) {
        for (auto itr = lv[i]->begin(); itr != lv[i]->end(); ++itr) {
            cout << " " << (*itr)->data;
        }
        cout << endl;
    }
    return 0;
}
