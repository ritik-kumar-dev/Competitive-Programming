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
  // dp[i]->>. max pages that we can buy upto amount i from the given books
  int n,x;
  cin>>n>>x;

  int price[n],pages[n];
  foo(i,0,n){
    cin>>price[i];
  }
  
  foo(i,0,n){
    cin>>pages[i];
  }

  vector<int> dp(x + 1, 0);
  foo(j,0,n){
    for(int i=x;i>=price[j];i--){
        if(i-price[j]>=0){
            dp[i]=max(dp[i],dp[i-price[j]]+pages[j]);
        }
    }
  }

  ct<<dp[x]<<ed;
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
