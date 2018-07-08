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
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <iterator>
#include <pthread.h>
#include <string.h>

#define ll long long

using namespace std;

/*
shared folder, confidential folder
explicit member for each folder
- explicit member and cows having access to the parent folder can access shared folder
- only explicit member can access confidential folder
leaf folder does not have any child
cows are uncool if there is at least one leaf they cannot access
determine which cows are uncool.

Input:
Q(#cows)
M(#shared folder) N(#confidential folder)
sharedfolderid1 K(#explicit cows) cowid1 cowid2 .. cowidK
sharedfolderid2 K(#explicit cows) cowid1 cowid2 .. cowidK
.
sharedfolderidM K(#explicit cows) cowid1 cowid2 .. cowidK
confidentialfolderid1 K(#explicit cows) cowid1 cowid2 .. cowidK
confidentialfolderid2 K(#explicit cows) cowid1 cowid2 .. cowidK
.
confidentialfolderidN K(#explicit cows) cowid1 cowid2 .. cowidK
G
U(parent) V(child)
U(parent) V(child)
... G times

output:
uncoolcowid1 uncoolcowid2 ...
*/
int main()
{
    int Q, M, N, G;
    cin >> Q;
    cin >> M >> N;
    unordered_map<int, unordered_set<int>> sharedfolder;
    unordered_map<int, unordered_set<int>> conffolder;
    int i;
    for (i = 0; i < M; i++) {
        int folderid, K, ex_cow;
        cin >> folderid >> K;
        unordered_set<int> ex_cows;
        while (K--) {
            cin >> ex_cow;
            ex_cows.insert(ex_cow);
        }
        sharedfolder[folderid] = ex_cows;
    }
    for (i = 0; i < N; i++) {
        int folderid, K, ex_cow;
        cin >> folderid >> K;
        unordered_set<int> ex_cows;
        while (K--) {
            cin >> ex_cow;
            ex_cows.insert(ex_cow);
        }
        conffolder[folderid] = ex_cows;
    }
    cin >> G;
    unordered_map<int, vector<int>> childfolders;
    int root; bool rootflg = true;
    while (G--) {
        int U, V;
        cin >> U >> V;
        // find root
        if (rootflg) {
            root = U;
            rootflg = false;
        } else {
            if (V == root) {
                root = U;
            }
        }
        childfolders[U].push_back(V);
    }
    set<int> allcows, resultcows, uncoolcows;
    while (Q--) {
        allcows.insert(Q);
    }
    queue<int> bfsq;
    bfsq.push(root);
    while (!bfsq.empty()) {
        root = bfsq.front();
        bfsq.pop();
        bool shared = sharedfolder.find(root) != sharedfolder.end();
        if (childfolders.find(root) == childfolders.end()) {
            // it's leaf node
            resultcows = allcows;
            if (shared) {
                for (auto itr = sharedfolder[root].begin(); itr != sharedfolder[root].end(); ++itr) {
                    resultcows.erase(*itr);
                }
            } else {
                for (auto itr = conffolder[root].begin(); itr != conffolder[root].end(); ++itr) {
                    resultcows.erase(*itr);
                }
            }
            uncoolcows.insert(resultcows.begin(), resultcows.end());
        } else {
            for (i = 0; i < childfolders[root].size(); i++) {
                int child = childfolders[root][i];
                bool childshared = sharedfolder.find(child) != sharedfolder.end();
                if (childshared) {
                    if (shared) {
                        sharedfolder[child].insert(sharedfolder[root].begin(), sharedfolder[root].end());
                    }
                }
                bfsq.push(child);
            }
        }
    }
    for (auto itr = uncoolcows.begin(); itr != uncoolcows.end(); ++itr) {
        if (itr == uncoolcows.begin()) {
            cout << *itr;
        } else {
            cout << " " << *itr;
        }
    }
    cout << endl;
    return 0;
}
