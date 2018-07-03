class Solution {
public:
    // Create comparison function
    // Time O(nlog(n)) Space O(1)
static bool comparefunc(const int a, const int b)
{
    int digita = 1, digitb = 1;
    long long tmpa = a, tmpb = b;
    while (tmpa / 10) {
        tmpa /= 10;
        digita++;
    }
    while (tmpb / 10) {
        tmpb /= 10;
        digitb++;
    }
    tmpa = a * pow(10, digitb) + b;
    tmpb = b * pow(10, digita) + a;
    cout << tmpa << " " << tmpb << endl;
    return tmpa > tmpb;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparefunc);
        string rt = "";
        for (int i = 0; i < nums.size(); i++) {
            string tmp = to_string(nums[i]);
            rt += tmp;
        }
        while (rt[0] == '0') {
            rt.erase(rt.begin());
        }
        return rt.size() == 0 ? "0" : rt;
    }
};


    // Wrong Answer
    // recursively check first digits
    // if ["34", "3"], it have to produce "343" but it is producing "334" because it only checks the first digit.
    void digger(vector<tuple<int, int, int>> &first_digit, int &cur, int &cur_end)
    {
        while (cur < cur_end) {
            if (get<1>(first_digit[cur]) == -1) {
                cur++;
                continue;
            }
            int same_digit_end = cur, digit = get<0>(first_digit[cur]);
            while (same_digit_end < cur_end && get<0>(first_digit[same_digit_end]) == digit) {
                int num = get<2>(first_digit[same_digit_end]);
                int digit = -get<1>(first_digit[same_digit_end]) - 1;
                get<0>(first_digit[same_digit_end]) = (num / (int)pow(10, digit)) % 10;
                get<1>(first_digit[same_digit_end]) = -digit;
                same_digit_end++;
            }
            if (same_digit_end == cur + 1) {
                cur++;
                continue;
            }
            sort(first_digit.begin() + cur, first_digit.begin() + same_digit_end, greater<tuple<int, int, int>>());
            digger(first_digit, cur, same_digit_end);
        }
    }
    string largestNumber(vector<int>& nums) {
        vector<tuple<int, int, int>> first_digit;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            int num_digits = 1;
            while (tmp / 10) {
                num_digits++;
                tmp /= 10;
            }
            first_digit.emplace_back(tmp, -num_digits, nums[i]);
        }
        sort(first_digit.begin(), first_digit.end(), greater<tuple<int, int, int>>());

        int cur = 0, cur_end = nums.size();
        digger(first_digit, cur, cur_end);
        string rt = "";
        for (int i = 0; i < nums.size(); i++) {
            string tmp = to_string(get<2>(first_digit[i]));
            rt += tmp;
        }
        return rt;
    }
};
