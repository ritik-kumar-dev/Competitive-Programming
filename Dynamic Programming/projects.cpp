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

struct project{
    int end;
    int start;
    int bonus;
};

int bin_search(const vector<project> &arr,int val){
    int l=0;
    int r=arr.size()-1;

    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(arr[mid].end<val){
            ans=max(ans,mid);
            l=mid+1;
        } else {
            r=mid-1;
        }
    }

    return ans+1;
}

void soln() {
// we have to be like dp[i]=max score at chossing 1st i projects and we have to either pick or unpick the the interval 
// if picked we need to see prev picked interval last date i-1 using bin search
int n;
cin>>n;

vector<project> arr(n);

foo(i,0,n){
    int x,y,z;
    cin>>x>>y>>z;
    arr[i].end=y;
    arr[i].start=x;
    arr[i].bonus=z;
}

sort(arr.begin(),arr.end(), [](const project &a, const project &b) {
    return a.end < b.end;
});

vector<int> dp(n+1); // max score storing
dp[0]=0;

foo(i,1,n+1){
    // unpick
    int unpick=dp[i-1];

    // if pick lets find the j using bin search
    int j=bin_search(arr,arr[i-1].start);
    int pick=dp[j]+arr[i-1].bonus;

    dp[i]=max(unpick,pick);
}

ct<<dp[n]<<ed;


     
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
