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
#include <sstream>
#include <iterator>
#include <pthread.h>

#define ll long long

using namespace std;

class Parser {
    struct Node {
        virtual string toString() = 0;
    };
    struct ObjectNode : Node {
        map<string, Node*> key2Node;
        string toString() {
            abort();
            return "";
        }
    };
    struct NumberNode : Node {
        long long value;
        string toString() {
            return to_string(value);
        }
    };
    struct StringNode : Node {
        string value;
        string toString() {
            return "\"" + value + "\"";
        }
    };
    struct TrueNode : Node {
        string toString() {
            return "true";
        }
    };
    struct FalseNode : Node {
        string toString() {
            return "false";
        }
    };
    struct NullNode : Node {
        string toString() {
            return "null";
        }
    };
    inline void skipWhiteSpaces(const string& s, int& cursor) {
        while (isspace(s[cursor])) cursor++;
    }
    StringNode* parseString(const string& s, int &cursor) {
        auto node = new StringNode();
        assert(s[cursor++] == '"');
        string value = "";
        while (s[cursor] != '"') {
            value += s[cursor++];
        }
        assert(s[cursor++] == '"');
        node->value = value;
        return node;
    }
    NumberNode *parseNumber(const string& s, int& cursor) {
        auto node = new NumberNode();
        bool negative = false;
        if (s[cursor] == '-') {
            negative = true;
            cursor++;
        }
        long long value = 0;
        while (isdigit(s[cursor])) {
            value = 10 * value + (s[cursor++] - '0');
        }
        if (negative) value = -value;
        node->value = value;
        return node;
    }
    TrueNode *parseTrue(const string& s, int& cursor) {
        assert(s[cursor++] == 't');
        assert(s[cursor++] == 'r');
        assert(s[cursor++] == 'u');
        assert(s[cursor++] == 'e');
        return new TrueNode();
    }
    FalseNode *parseFalse(const string& s, int& cursor) {
        assert(s[cursor++] == 'f');
        assert(s[cursor++] == 'a');
        assert(s[cursor++] == 'l');
        assert(s[cursor++] == 's');
        assert(s[cursor++] == 'e');
        return new FalseNode();
    }
    NullNode *parseNull(const string& s, int& cursor) {
        assert(s[cursor++] == 'n');
        assert(s[cursor++] == 'u');
        assert(s[cursor++] == 'l');
        assert(s[cursor++] == 'l');
        return new NullNode();
    }
    Node *parseValue(const string& s, int& cursor) {
        if (s[cursor] == '"') {
            return parseString(s, cursor);
        } else if (isdigit(s[cursor]) || s[cursor] == '-') {
            return parseNumber(s, cursor);
        } else if (s[cursor] == '{') {
            return parseObject(s, cursor);
        } else if (s[cursor] == 't') {
            return parseTrue(s, cursor);
        } else if (s[cursor] == 'f') {
            return parseFalse(s, cursor);
        } else if (s[cursor] == 'n') {
            return parseNull(s, cursor);
        } else abort();
    }
public:
    ObjectNode* parseObject(const string& s, int &cursor) {
        auto node = new ObjectNode();
        skipWhiteSpaces(s, cursor);
        assert(s[cursor++] == '{');
        while (true) {
            skipWhiteSpaces(s, cursor);
            auto key = parseString(s, cursor);
            skipWhiteSpaces(s, cursor);
            assert(s[cursor++] == ':');
            skipWhiteSpaces(s, cursor);
            auto value = parseValue(s, cursor);
            node->key2Node[key->value] = value;
            skipWhiteSpaces(s, cursor);
            if (s[cursor] == '}') break;
            assert(s[cursor++] == ',');
        }
        assert(s[cursor++] == '}');
        return node;
    }
    string access(ObjectNode *node, string property) {
        replace(property.begin(), property.end(), '.', ' ');
        istringstream in(property);
        string p;
        Node* current = node;
        while (in >> p) {
            ObjectNode* object = dynamic_cast<ObjectNode*>(current);
            if (object == NULL) return "null";
            if (object->key2Node.count(p) == 0) {
                return "null";
            }
            current = object->key2Node[p];
        }
        return current->toString();
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    string line;
    getline(cin, line);
    string json = "";
    for (int i = 0; i < N; i++) {
        getline(cin, line);
        json += line + "\n";
    }
    Parser parser;
    int cursor = 0;
    auto object = parser.parseObject(json, cursor);
    for (int i = 0; i < Q; i++) {
        string s;
        cin >> s;
        cout << parser.access(object, s) << endl;
    }
    return 0;
}
