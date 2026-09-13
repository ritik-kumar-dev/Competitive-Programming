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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    foo(i,1,n+1){
        foo(j,1,m+1){
             if(i==j){
                dp[i][j]=0;
             } else {
                dp[i][j]=1e9;

                // horizontal cuts
                foo(k,1,i){
                    dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                }

                //vertical cuts
                foo(k,1,j){
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
             }
        }
    }

    cout<<dp[n][m]<<endl;
     
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