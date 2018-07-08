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
#include <pthread.h>

#define ll long long

using namespace std;

class Graph
{
    int V; // No. of vertices
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void Graph::topologicalSort()
{
    vector<int> in_degree(V, 0); // create a vector to store indegrees of all vertices
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            in_degree[*itr]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }
    int cnt = 0;
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
        list<int>::iterator itr;
        for (itr = adj[u].begin(); itr != adj[u].end(); itr++) {
            if (--in_degree[*itr] == 0)
                q.push(*itr);
        }
        cnt++;
    }
    if (cnt != V) {
        cout << "Cycle" << endl;
        return;
    }
    for (int i = 0; i < top_order.size(); i++) {
        cout << top_order[i] << " ";
    }
    cout << endl;
}

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    cout << "Following is a topological sort of\n";
    g.topologicalSort();
    return 0;
}
