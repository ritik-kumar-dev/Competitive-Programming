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

int bin_search(vector<int> &dp,int val){
    int l=0;
    int r=dp.size()-1;

    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(val>dp[mid]){
            l=mid+1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }

    return ans;
}

void soln() {
// 1 2 3 2 1 2 
// 7 3 5 3 6 2 9 8   dp[i]=max length of the subsequence from 0 to i
// if a[i]<a[i-1]->dp[i]=dp[i-1]
// else dp[i]=dp[i-1]+1; but ye worng h hum n^2 m kr kste h like i p hum phir se 0 to i-1 tak dekhe kis dp state ki jyada value thi

// New approach
 /*
 * Note: 'dp' DOES NOT store the actual subsequence.
 * dp[i] = smallest ending element of an increasing subsequence of length (i+1).
 * 
 * For each element 'x':
 * 1. If x > dp.back(): Append 'x' (increases overall max length).
 * 2. Else: Use lower_bound to find the first element >= x, and replace it with 'x'.
 * 
 * WHY REPLACE? 
 * It lowers the ending value of that specific length, making it easier 
 * for future numbers to attach and potentially create longer subsequences!
 */ 

 int n;
 cin>>n;

 vector<int> arr(n);
 foo(i,0,n){
    cin>>arr[i];
 }

 vector<int> dp;

 dp.pb(arr[0]);
 foo(i,1,n){
    if(arr[i]>dp.back()){
        dp.pb(arr[i]);
    } else {
        int idx= bin_search(dp,arr[i]);
        dp[idx]=arr[i];
    }
 }

 ct<<dp.size()<<ed;
 
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