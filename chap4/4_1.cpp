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

class Graph {
    private:

    public:
    class Node
    {
        public:
        string name;
        bool visited = false;
        vector<Node *> children;
    };
    vector<Node> nodes;
    void dfs(Node *root, void (*visit)(Node *))
    {
        if (root == NULL) return;
        visit(root);
        root->visited = true;
        for (Node *n : root->children) {
            if (n->visited == false) {
                dfs(n, visit);
            }
        }
    }

    void bfs(Node *root, void (*visit)(Node *))
    {
        queue<Node *> q;
        root->visited = true;
        q.push(root);

        while (!q.empty()) {
            Node *r = q.front();
            q.pop();
            visit(r);
            for (Node *n : root->children) {
                if (n->visited == false) {
                    n->visited = true;
                    q.push(n);
                }
            }
        }
    }
};

void nothing(Graph::Node *r)
{
    return;
}

bool routeBtw2Nodes(Graph *g, Graph::Node *n1, Graph::Node *n2)
{
    g->bfs(n1, nothing);
    if (n2->visited) return true;
    else return false;
}

int main()
{
    return 0;
}
