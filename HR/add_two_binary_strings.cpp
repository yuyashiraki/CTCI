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
#include <iterator>
#include <pthread.h>
#include <sstream>

#define ll long long
using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int apos = a.size() - 1, bpos = b.size() - 1, carry = 0;
    while (apos >= 0 || bpos >= 0 || carry) {
        if (apos >= 0) {
            carry += a[apos--] - '0';
        }
        if (bpos >= 0) {
            carry += b[bpos--] - '0';
        }
        result = char(carry % 2 + '0') + result;
        carry /= 2;
    }
    return result;
}

// Driver program
int main()
{
    string a = "11", b="1";
    cout << addBinary(a, b) << endl;
    return 0;
}
