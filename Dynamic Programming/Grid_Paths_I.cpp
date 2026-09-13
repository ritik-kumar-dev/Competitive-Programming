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
   // dp[i][j]= the number of the paths from upper right corner cond only i get. to the cell either from the top or left
   int n;
   cin>>n;
   vector<vector<char>> arr(n,vector<char>(n));
   vector<vector<int>> dp(n,vector<int>(n));
   foo(i,0,n){
    foo(j,0,n){
        cin>>arr[i][j];
    }
   }

   if(arr[0][0]!='*')dp[0][0]=1;
   foo(i,0,n){
    foo(j,0,n){
        if(arr[i][j]!='*'){
            if(i-1>=0)dp[i][j]+=dp[i-1][j];
            if(j-1>=0)dp[i][j]+=dp[i][j-1];
            dp[i][j]%=MOD;
        } else {
            dp[i][j]=0;
        }
    }
   }

   cout<<dp[n-1][n-1]%MOD<<endl;
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
