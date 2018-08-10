
#include <bits/stdc++.h>

using namespace std;

// Using stack
// Time O(n)  Space O(n)
char opposite(char x) {
    switch(x) {
        case '{':
            return '}';
        case '}':
            return '{';
        case '[':
            return ']';
        case ']':
            return '[';
        case '(':
            return ')';
        case ')':
            return '(';
        default:
            return '#';
    }
}
string isBalanced(string s) {
    if (s.size() % 2) return "NO";
    stack<char> STK;
    for (int i = 0; i < s.size(); i++) {
        if ('{' == s[i] || '[' == s[i] || '(' == s[i]) STK.push(opposite(s[i]));
        else if (STK.empty() || STK.top() != s[i]) return "NO";
        else STK.pop();
    }
    if (STK.empty()) return "YES";
    else return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
