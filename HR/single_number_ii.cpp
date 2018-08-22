class Solution {
public:
    /* state machine (bitwise)
     * after 3 appearance, go back to 0
     * Truth Table:
     * a b  num  --> a b
     * 0 0    0      0 0
     * 0 1    0      0 1
     * 1 0    0      1 0
     * 0 0    1      0 1
     * 0 1    1      1 0
     * 1 0    1      0 0
     *
     * From truth table,
     * a = a & ~b & c  OR  ~a & b & c
     * b = ~a & ~b & c OR  ~a & b & ~c
     *
     * Time O(n)  Space O(1)
     */
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            int ta = (a&~b&~nums[i]) | (~a&b&nums[i]);
            int tb = (~a&~b&nums[i]) | (~a&b&~nums[i]);
            a = ta;
            b = tb;
        }
        return b;
    }
};
