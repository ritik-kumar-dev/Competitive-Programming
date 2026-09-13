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
    int n;
    cin>>n;
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;

    foo(i,3,n+1){
       foo(j,1,7){
         if(i-j>=0)dp[i]+=dp[i-j];
       }
       dp[i] %= 1000000007;
    }
    

    cout<<dp[n]<<endl;
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