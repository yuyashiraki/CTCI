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

/* Prime Numbers */
bool primeNaive(int n)
{
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool primeSlightlyBetter(int n)
{
    if (n < 2) {
        return false;
    }
    int sqr = sqrt(n); 
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool *sieveOfEratosthenes(int max)
{
    bool *flags = new bool[max + 1];
    int count = 0;
    
    // Set all flags to true other than 0 and 1
    flags[0] = flags[1] = false;
    for (int i = 2; i <= max; i++) flags[i] = true;

    int prime = 2;
    while (prime <= sqrt(max)) {
        crossOff(flags, prime);
        prime = getNextPrime(flags, prime);
    }
    return flags;
}

void crossOff(bool *flags, int prime)
{
    // Cross off remaining multiples of prime.
    for (int i = prime * prime; i < len(flags); i += prime) {
        flags[i] = false;
    }
}

int getNextPrime(bool *flags, int prime)
{
    int next = prime + 1;
    while (next < len(flags) && !flags[next]) {
        next++;
    }
    return next;
}


/*
 * Probability 
 * P(A and B) = P(B given A)*P(A) = P(A given B)*P(B)
 * P(A or B) = P(A) + P(B) - P(A and B)
 * Independence: P(A and B) = P(A)*P(B), P(B given A) = P(B)
 * Mutual Exclusive: P(A or B) = P(A) + P(B), P(A and B) = 0
 *
 */

/*
 * Develop Rules and Patterns
 * Q: You have two ropes, and each takes exactly one hour to burn. How would you use them to time exactly 15 minutes?
 */

/*
 * Worst Case Shifting
 * You have nine balls. Eight are of the same weight, and one is heavier. You are given a balance which tells you only whether the left side or the right side is heavier. Find the heavy ball in just two uses of the scale
 *
 */
int main()
{
    return 0;
}
