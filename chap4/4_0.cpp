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

class Tree
{
    private:
    class Node
    {
        public:
        string name;
        vector<Node> children;
    };

    public:
    Node *root;
    void inOrderTraversal(Node *node)
    {
        // left -> root -> right
        if (node != NULL) {
            inOrderTraversal(node.left);
            visit(node);
            inOrderTraversal(node.right);
        }
    }
    
    void preOrderTraversal(Node *node)
    {
        // root -> left -> right
        if (node != NULL) {
            visit(node);
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
    }
    
    void postOrderTraversal(Node *node)
    {
        // left -> right -> root
        if (node != NULL) {
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            visit(node);
        }
    }
};


class Graph {
    private:
    class Node
    {
        public:
        string name;
        bool visited = false;
        vector<Node *> children;
    };

    public:
    vector<Node> nodes;
    void dfs(Node *root)
    {
        if (root == NULL) return;
        visit(root);
        root->visited = true
        for (Node *n : root->children) {
            if (n->visited == false) {
                dfs(n);
            }
        }
    }

    void bfs(Node *root)
    {
        queue<Node *> q;
        root->visited = true;
        q.push_back(root);

        while (!q.empty()) {
            Node *r = q.pop_front();
            visit(r);
            for (Node *n : root->children) {
                if (n->visited == false) {
                    n->visited = true;
                    q.push_back(n);
                }
            }
        }
    }
};


#define NUM_NODES 100
bool graph_matrix[NUM_NODES][NUM_NODES];

int main()
{
    return 0;
}
