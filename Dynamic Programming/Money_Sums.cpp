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
    vector<int> coins(n);
    int max_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        max_sum += coins[i]; // The maximum possible sum
    }

    // dp[s] will be true if sum 's' is possible
    vector<bool> dp(max_sum + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        // Iterate backwards to avoid reusing the current coin
        for (int j = max_sum; j >= coin; j--) {
            if (dp[j - coin]) {
                dp[j] = true;
            }
        }
    }

    // Collect all possible sums (excluding 0)
    vector<int> possible_sums;
    for (int j = 1; j <= max_sum; j++) {
        if (dp[j]) {
            possible_sums.push_back(j);
        }
    }

    // Print results
    cout << possible_sums.size() << "\n";
    for (int sum : possible_sums) {
        cout << sum << " ";
    }
    cout << "\n";  
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--) 
    soln();

    return 0;
}
