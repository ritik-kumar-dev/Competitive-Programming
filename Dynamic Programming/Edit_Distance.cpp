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
    string a,b;
    cin>>a>>b;

    int n=a.size();
    int m=b.size();
    

    vector<vector<int>> dp(n+1,vector<int>(m+1,1e6));
    // dp[i][j]=edit distance bw i characters of a and j charactes of the b
    // base cases
    // bcs if the i char are left in one string and other is exhausted then we need to either remove the i chars or add i chars
    foo(i,0,n+1){
        dp[i][0]=i;
    }

    foo(i,0,m+1){
        dp[0][i]=i;
    }

    foo(i,1,n+1){
        foo(j,1,m+1){
            if(a[i-1]==b[j-1]){
                // characters are matching no need to do any thing
                dp[i][j]=dp[i-1][j-1];
            } else {
                // we can do 3 ops add, remove and replace although add or remove are the same
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1); // replace
                dp[i][j]=min(dp[i][j],dp[i-1][j]+1); //remove or add from first
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1); // remove or add from second 
            }
        }
    }
    

    cout<<dp[n][m]<<ed;

     
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
