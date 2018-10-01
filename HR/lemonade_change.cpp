class Solution {
public:
    // counting each bills
    // Time O(n)  Space O(1)
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives == 0) return false;
                fives--;
                tens++;
            } else if (bills[i] == 20) {
                if (tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                } else if (fives > 2) {
                    fives -= 3;
                } else {
                    return false;
                }
            } else {
                cout << "ERROR: UNKNOWN BILL" << endl;
            }
        }
        return true;
    }
};
