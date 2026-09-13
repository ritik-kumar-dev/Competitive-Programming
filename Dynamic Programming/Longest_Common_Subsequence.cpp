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

  vector<int> a(n+1),b(m+1);

  foo(i,1,n+1)cin>>a[i];
  foo(i,1,m+1)cin>>b[i];

  vector<vector<int>> dp(n+1,vector<int>(m+1,0));

  // dp[i][j]== LCS for i characters in string a and j characters in the string b

  dp[0][0]=0;

  foo(i,1,n+1){
    foo(j,1,m+1){
        if(a[i]==b[j]){
            dp[i][j]= 1+ dp[i-1][j-1];
        } else {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
  }

  // backtrack the soln
  int i=n;
  int j=m;
  vector<int> lcs;

  while(i>0 && j>0){
     if(a[i]==b[j]){
        // always the part of the LCS
        lcs.pb(a[i]);
        i--;
        j--;
     } else if (dp[i-1][j]>dp[i][j-1]){
        
        i--;
     } else {
        j--;
     }
  }

  reverse(lcs.begin(),lcs.end());

  ct<<dp[n][m]<<endl;
  foo(i,0,lcs.size()){
    ct<<lcs[i]<<" ";
  }
  ct<<endl;
     
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