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
     int n;
     cin>>n;
     
     vector<vector<int>> dp(n,vector<int>(n));
     vector<int> x(n);

     int sum=0;
     foo(i,0,n){
        cin>>x[i];
        sum+=x[i];
     }

     foo(i,0,n){
        dp[i][i]=x[i];
     }


     //dp[i][j]=max diff bw score of player 1 and player 2 in seg i,j

     foo(seg_len,2,n+1){
        foo(i,0,n-seg_len+1){
            int j=i+seg_len-1; // last element of the seg

            int left_pick=x[i]-dp[i+1][j];
            int right_pick=x[j]-dp[i][j-1];

            dp[i][j]=max(left_pick,right_pick);
        }
     }

     int max_diff=dp[0][n-1];// max score diff bw P1 and P2 (P1-P2)
     // sum =P1+P2 if we add we get 2P1/2=P1 = max score of the P1

     ct<<(max_diff+sum)/2<<endl;

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