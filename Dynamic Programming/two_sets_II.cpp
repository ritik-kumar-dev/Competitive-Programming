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
    cin>>n;
long long total_sum = n * (n + 1) / 2;

if (total_sum % 2 != 0) {
    cout << 0 << endl;
    return;
}

long long target = total_sum / 2;
vector<long long> dp(target + 1, 0);
dp[0] = 1; // 1 way to make a sum of 0

// Only loop up to n - 1 to handle the divide-by-two symmetry
for (int i = 1; i < n; i++) {
    for (int j = target; j >= i; j--) {
        dp[j] = (dp[j] + dp[j - i]) % MOD;
    }
}

cout << dp[target] << endl;
     
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