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

void soln(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    foo(i,0,n)cin>>a[i];

    const int INF = 1e18;
    vector<int> dp(x+1,INF);
    dp[0]=0;

    foo(i,1,x+1){
        foo(j,0,n){
            if(i-a[j]>=0) dp[i]=min(dp[i],dp[i-a[j]]+1);
        }
    }

    ct<<(dp[x]==INF ? -1 : dp[x])<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t;
    // cin >> t;
    //while (t--) 
    soln();

    return 0;
}
