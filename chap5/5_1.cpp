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
#include <bitset>
using namespace std;

int insertMtoNinItoJ(int N, int M, int i, int j)
{
    int mask = ~((1 << j) - (1 << i));
    return (N & mask) | (M << i);
}

int main()
{
    int a = insertMtoNinItoJ(0b10000000000, 0b1101, 3, 6);
    bitset<16> x(a);
    cout << x << endl;
    return 0;
}
