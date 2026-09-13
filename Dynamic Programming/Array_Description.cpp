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

void soln(){
   // we need to make a state such that we need to put the numbers in unknown such that cond full filled

   int n,m;
   cin>>n>>m;

   int a[n];
   foo(i,0,n)cin>>a[i];

   // dp[i][j] stores the number of valid arrays up to index i ending with value j
    // We use m + 1 so we can 1-index the values up to m safely
   vector<vector<int>> dp(n,vector<int>(m+1,0));

   // base case 
   if(a[0]!=0){
     dp[0][a[0]]=1;
   } else {
      foo(i,1,m+1){
        dp[0][i]=1;
      }
   }

foo(i,1,n){
    if(a[i]!=0){
        // fixed value so we will see prev ways we have with a[i]+-1 and a[i] valuie upto i-1
        int j=a[i];
        int ways=dp[i-1][j];
        if(j-1>=1) ways=(ways+dp[i-1][j-1])%MOD;
        if(j+1<=m) ways=(ways+dp[i-1][j+1])%MOD;
        dp[i][j]=ways;
    } else {
        // we gonna set the value in this based on that val we set we add the prev i-1 (val,val+1,val-1)
        foo(j,1,m+1){
          int ways=dp[i-1][j];
          if(j-1>=1) ways=(ways+dp[i-1][j-1])%MOD;
          if(j+1<=m) ways=(ways+dp[i-1][j+1])%MOD;
          dp[i][j]=ways;
        }
    }

    }
    int tways=0;

    foo(j,1,m+1){
        tways=(tways+dp[n-1][j])%MOD;
    }

    cout<<tways<<endl;
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
