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
using namespace std;

/*
1's complement:
    The maximum number which does not have a carry when added.
    == Bit inversion
2's complement:
    The smallest number which does make a carry when added.
    == Bit inversion + 1
*/

int repeatedArithmeticShift(int x, int count)
{
    // Arithmetic right shift fill the new bits with the value of the sign bit
    for (int i = 0; i < count; i++) {
        x >>= 1;
    }
    return x;
}

int repeatedLogicalShift(int x, int count)
{
    // Logical right shift just shift without considering the sign bit
    for (int i = 0; i < count; i++) {
        (unsigned int) x >>= 1;
    }
    return (int) x;
}

bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}

int setBit(int num, int i)
{
    return num | (1 << i);
}

int clearBit(int num, int i)
{
    int mask = ~(1 << i);
    return num & mask;
}

int clearBitsMSBthroughI(int num, int i)
{
    int mask = (1 << i) - 1;
    return num & mask;
}

int clearBitsIthrough0(int num, int i)
{
    int mask = (-1 << (i + 1));
}

int updateBit(int num, int i, bool bitIs1)
{
    int value = bitIs1 ? 1 : 0;
    int mask = ~(1 << i);
    return (num & mask) | (value << i);
}

int main()
{
    return 0;
}
