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
#define int           long long
using namespace std;

void soln() {
    int n;
    cin>>n;
    int a[n];
    foo(i,0,n)cin>>a[i]; 
    
    
    if (n == 1) {
        cout << a[0] << "\n";
        return;
    }

    // base case 
    int dp[n][2];
    dp[0][0]=a[0];
    dp[0][1]=1e9;

    dp[1][0]=a[0]+a[1];
    dp[1][1]=dp[0][0];


    foo(i,2,n){
        dp[i][0]=min(dp[i-1][1]+a[i],dp[i-2][1]+a[i]+a[i-1]);
        dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
    }

    cout<<min(dp[n-1][0],dp[n-1][1])<<ed;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) soln();

    return 0;
}
