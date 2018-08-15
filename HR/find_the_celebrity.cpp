// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    // 2 pass
    // Time O(n)  Space O(1)
    int findCelebrity(int n) {
        int candidate = 0;
        for (int i = 0; i < n; i++) {
            if (knows(candidate, i))
                candidate = i;
        }
        for (int i = 0; i < n; i++) {
            if (candidate == i) continue;
            if (knows(i, candidate) && !knows(candidate, i)) continue;
            else return -1;
        }
        return candidate;
    }
    // Count numbers
    // Time O(n^2) Space O(n)
    int findCelebrity(int n) {
        vector<int> incounter(n, 0), outcounter(n,0);
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                if (a == b) continue;
                if (knows(a, b)) {
                    incounter[b]++;
                    outcounter[a]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (incounter[i] == n - 1 && outcounter[i] == 0) return i;
        }
        return -1;
    }
};
