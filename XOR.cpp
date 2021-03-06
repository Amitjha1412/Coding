#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1 << 17;

int T, n;
int A[MAX];

int main()
{
    // Read the number of test cases
    scanf("%d", &T);
    FOR(test, 0, T)
    {
        // Read N and array A
        scanf("%d", &n);
        FOR(i, 0, n)
            scanf("%d", &A[i]);
        Int res = 0;
        // Try all powers of 2
        FOR(p, 0, 31)
        {
            int c[2] = { 0, 0 };
            int sum = 0;
            Int cnt = 0;
            // Find the result
            FOR(i, 0, n)
            {
                ++c[sum];
                sum = (sum + ((A[i] & (1 << p)) != 0)) % 2;
                // Add to the result current number of positions
                cnt += c[sum ^ 1];
            }
            res += cnt * (1 << p);
        }
        // Output the result
        printf("%lld\n", res);
    }



    return 0;
}
