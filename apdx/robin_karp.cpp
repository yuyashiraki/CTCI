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
#include <string.h>

#define ll long long
#define d 256

using namespace std;

/* pat: pattern, txt: text, q: prime num */
void search(char pat[], char txt[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    for (i = 0; i < M - 1; i++) {
        h = (h*d) % q;
    }
    for (i = 0; i < M; i++) {
        p = (d*p + pat[i]) % q;
        t = (d*t + txt[i]) % q;
    }
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == M) {
                cout << "pattern found at index " << i << endl;
            }
        }
        if (i < N - M) {
            t = (d * (t - txt[i]*h) + txt[i + M]) % q;
            if (t < 0) {
                t = (t + q);
            }
        }
    }
}


int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101;
    search(pat, txt, q);
    return 0;
}
