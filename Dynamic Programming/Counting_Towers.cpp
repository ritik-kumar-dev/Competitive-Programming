// JOSH TYPE//
// Submission by Ritik Jaat //
#include <bits/stdc++.h>
#define ll            long long 
#define pb            push_back
#define ld            long double
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define m_p           make_pair
#define vi            vector<ll>
#define vpll           vector<pll>
#define ff            first
#define ss            second
#define mod           998244353
#define MOD           1000000007
#define int           long long
using namespace std;

void soln() {
    int n;
    cin >> n;

    // dp[i][0] -> Number of ways to build a tower of height i where the top row has TWO separate blocks of width 1.
    // dp[i][1] -> Number of ways to build a tower of height i where the top row has ONE single block of width 2.
    // Using long long for dp array is safer to avoid overflow during addition before modulo.
    long long dp[n + 1][2];

    // Base cases for height 1
    dp[1][0] = 1; // 2 separate blocks of 1x1
    dp[1][1] = 1; // 1 solid block of 2x1

    // Loop to build the tower layer by layer up to height n
    foo(i, 2, n + 1) {
        
        // --- Calculating ways to reach state 0 (Two separate blocks at top) ---
        // If previous state was 0 (Two blocks):
        // 1. Extend both blocks upwards.
        // 2. Extend left block, place a new block on the right.
        // 3. Place a new block on the left, extend the right block.
        // 4. Place two completely new blocks.
        // -> This gives 4 combinations. (dp[i-1][0] * 4)
        //
        // If previous state was 1 (One big block):
        // 1. Place two new separate blocks on top.
        // -> This gives 1 combination. (dp[i-1][1] * 1)
        dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % MOD;

        // --- Calculating ways to reach state 1 (One single block at top) ---
        // If previous state was 0 (Two blocks):
        // 1. Place a single new block of width 2 on top. (We cannot extend from two blocks into one).
        // -> This gives 1 combination. (dp[i-1][0] * 1)
        //
        // If previous state was 1 (One big block):
        // 1. Extend the big block upwards.
        // 2. Place a new single block of width 2 on top.
        // -> This gives 2 combinations. (dp[i-1][1] * 2)
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
    }

    // Final answer is the sum of ways to finish with either state 0 or state 1 at height n.
    cout << (dp[n][0] + dp[n][1]) % MOD << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) soln();

    return 0;
}
