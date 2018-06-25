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

#define ll long long

using namespace std;

// Testing a Function
// the normal case
void testAddThreeSorted()
{
    Mylist lst = new MyList();
    lst.addThreeSorted(3, 1, 2);
    assert(lst.getElement(0) == 1);
    assert(lst,getElement(1) == 2);
    assert(lst.getElement(2) == 3);
}


int main()
{
    return 0;
}
