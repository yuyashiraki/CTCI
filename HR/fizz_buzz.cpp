class Solution {
public:
    // Time O(n) Space O(n)
    vector<string> fizzBuzz(int n) {
        vector<string> rt;
        for (int i = 1; i <= n; i++) {
            string a;
            if (!(i % 3)) a.append("Fizz");
            if (!(i % 5)) a.append("Buzz");
            if (a.empty()) a = to_string(i);
            rt.push_back(a);
        }
        return rt;
    }
};
