class Solution {
public:
    vector<string> numToLetters(char num)
    {
        vector<string> ans;
        switch (num) {
            case '2': {
                string arr[] = {"a", "b", "c"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '3': {
                string arr[] = {"d", "e", "f"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '4': {
                string arr[] = {"g", "h", "i"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '5': {
                string arr[] = {"j", "k", "l"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '6': {
                string arr[] = {"m", "n", "o"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '7': {
                string arr[] = {"p", "q", "r", "s"};
                ans.insert(ans.begin(), arr, arr + 4);
                break;
            }
            case '8': {
                string arr[] = {"t", "u", "v"};
                ans.insert(ans.begin(), arr, arr + 3);
                break;
            }
            case '9': {
                string arr[] = {"w", "x", "y", "z"};
                ans.insert(ans.begin(), arr, arr + 4);
                break;
            }
            default: {
                break;
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v = numToLetters(digits[0]);;
        for (int i = 1; i < digits.size(); i++) {
            vector<string> new_v;
            vector<string> letters = numToLetters(digits[i]);
            while (!v.empty()) {
                string tmp = v.back();
                //cout << tmp << endl;
                v.pop_back();
                for (int j = 0; j < letters.size(); j++) {
                    new_v.push_back(tmp + letters[j]);
                }
            }
            v = new_v;
        }
        return v;
    }
};
