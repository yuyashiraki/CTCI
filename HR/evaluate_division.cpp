class Solution {
public:
    // Union Find
    class Node {
    public:
        double val;
        Node *parent;
    };
    Node *FindRoot(Node *c) {
        if (c->parent == c) return c;
        Node *p = FindRoot(c->parent);
        c->val *= c->parent->val;
        c->parent = p;
        return p;
    }
    void UnionNode(Node *c, Node *p, double val) {
        Node *parentc = FindRoot(c), *parentp = FindRoot(p);
        // p / c = val, parentc / c = c->val, parentp / p = p->val
        // parentp / parentc = (p * p->val) / (c * c->val) = val * p->val / c->val
        parentc->val = val * p->val / c->val;
        parentc->parent = parentp;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        unordered_map<string, Node*> MP;
        for (int i = 0; i < equations.size(); i++) {
            string c = equations[i].first, p = equations[i].second;
            double val = values[i];
            Node *cn, *pn;
            if (MP.count(c) && MP.count(p)) {
                cn = MP[c]; pn = MP[p];
                UnionNode(cn,pn,val);
            } else if (MP.count(c)) {
                cn = MP[c];
                pn = new Node();
                pn->parent = pn;
                pn->val = 1.0;
                UnionNode(cn,pn,val);
            } else if (MP.count(p)) {
                pn = MP[p];
                cn = new Node();
                cn->parent = pn;
                cn->val = val;
            } else {
                cn = new Node();
                pn = new Node();
                cn->parent = pn;
                cn->val = val;
                pn->parent = pn;
                pn->val = 1.0;
            }
            MP[c] = cn; MP[p] = pn;
        }
        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i].second, end = queries[i].first;
            if (!MP.count(start) || !MP.count(end) || FindRoot(MP[start]) != FindRoot(MP[end])) {
                ans.push_back(-1);
            } else {
                ans.push_back(MP[end]->val / MP[start]->val);
            }
        }
        return ans;
    }


    // Hash + DFS
    // Time O(n) per query  Space O(n)
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, vector<pair<string, double>>> MP;
        vector<double> ans;
        for (int i = 0; i < equations.size(); i++) {
            pair<string, string> eq = equations[i];
            double val = values[i];
            MP[eq.first].push_back(make_pair(eq.second, 1 / val));
            MP[eq.second].push_back(make_pair(eq.first, val));
        }
        for (int i = 0; i < queries.size(); i++) {
            string start = queries[i].second, end = queries[i].first;
            if (!MP.count(start) || !MP.count(end)) {
                ans.push_back(-1);
                continue;
            }
            bool found = false;
            unordered_set<string> visited;
            visited.insert(start);
            stack<pair<string, double>> STK;
            STK.emplace(start, 1);
            while (!STK.empty()) {
                string cur = STK.top().first;
                double curval = STK.top().second;
                STK.pop();
                visited.insert(cur);
                if (MP.count(cur)) {
                    vector<pair<string, double>> v = MP[cur];
                    for (int j = 0; j < v.size(); j++) {
                        if (v[j].first == end) {
                            ans.push_back(curval * v[j].second);
                            found = true;
                            break;
                        }
                        if (visited.count(v[j].first)) continue;
                        STK.emplace(v[j].first, curval * v[j].second);
                    }
                }
                if (found) break;
                MP[start].insert(MP[start].begin(), make_pair(cur,curval));
            }
            if (!found) ans.push_back(-1);
        }
        return ans;
    }
};
