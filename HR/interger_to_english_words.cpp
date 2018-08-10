class Solution {
public:
    vector<string> LESS_THAN_20 = vector<string>{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = vector<string>{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> THOUSANDS = vector<string>{"", "Thousand", "Million", "Billion"};
    string helper(int num) {
        if (num == 0) {
            return "";
        } else if (num < 20) {
            return LESS_THAN_20[num] + " ";
        } else if (num < 100) {
            return TENS[num / 10] + " " + helper(num % 10);
        } else {
            return LESS_THAN_20[num / 100] + " Hundred " + helper(num % 100);
        }
    }
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        int i = 0, j;
        string words = "";
        while (num > 0) {
            if (num % 1000 != 0) {
                words = helper(num % 1000) + THOUSANDS[i] + " " + words;
            }
            num /= 1000;
            i++;
        }
        for (i = 0; i < words.size(); i++) {
            if (words[i] == ' ') continue;
            else break;
        }
        for (j = words.size() - 1; j >= 0; j--) {
            if (words[j] == ' ') continue;
            else break;
        }
        return words.substr(i, j - i + 1);;
    }
};
