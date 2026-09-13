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
    int h[n];
    foo(i,0,n)cin>>h[i];
     int dp[n];
     dp[0]=0;
     dp[1]=abs(h[1]-h[0]);
     foo(i,2,n){
        dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
     } 

     cout<<dp[n-1]<<ed;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) soln();

    return 0;
}
