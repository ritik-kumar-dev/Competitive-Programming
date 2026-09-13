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
    // Removing digits
    // dp[n]= min steps to make it zero using the digits sub
    // dp[i] = min(dp[i],dp[i-d(1-9 that is the number)]+1)
    int n;
    cin>>n;
    
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    foo(i,1,n+1){
        int temp=i;
        while(temp!=0){
            int d=temp%10;
            if(i-d>=0) dp[i]=min(dp[i],dp[i-d]+1);
            temp/=10;
        }
    }

    cout<<dp[n]<<ed;
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
