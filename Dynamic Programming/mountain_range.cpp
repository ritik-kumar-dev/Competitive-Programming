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

const int MAXN=200005;
const int LOG=19;

int n;
int h[MAXN];

int sparse[LOG][MAXN]; // it stores like sparse[i][j]=min or max(of seg staring from j to j+2^i)
int lg[MAXN];

void build_rmq(){
    // Fast O(1) log calculation pre-computation
    lg[1]=0;
    foo(i,2,n+1){
        lg[i]=lg[i/2]+1;
    }

    foo(i,1,n+1){
        sparse[0][i]=i;
    }

    foo(i,1,LOG){
        for(int j=1;j+(1<<i)-1<=n;j++){
            int left=sparse[i-1][j];
            int right=sparse[i-1][j+(1<<(i-1))];

            // Compare heights, store the index of the taller mountain
            if (h[left] >= h[right]) {
                sparse[i][j] = left;
            } else {
                sparse[i][j] = right;
            }
        }
    }
}

int query_rmq(int L,int R){
    int len=R-L+1;
    int k=lg[len];

    int l=sparse[k][L];
    int r=sparse[k][R-(1<<k)+1];

    if(h[l]>=h[r]){
        return l;
    }

    return r;

}

pair<int,int> solve(int L,int R){
    if (L>R) return {0,0};

    int M=query_rmq(L,R);
    int max_val=h[M];

    int dp_val=1;

    if (L <= M - 1) {
        pair<int, int> left = solve(L, M - 1);
        if (left.first < max_val) {
            dp_val = max(dp_val, 1 + left.second); // We can glide to it!
        } else {
            dp_val = max(dp_val, left.second);     // Equal height blocks the glide
        }
    }

    // Go right
    if (M + 1 <= R) {
        pair<int, int> right = solve(M + 1, R);
        if (right.first < max_val) {
            dp_val = max(dp_val, 1 + right.second); // We can glide to it!
        } else {
            dp_val = max(dp_val, right.second);     // Equal height blocks the glide
        }
    }

    return {max_val, dp_val};

}

void soln() {
    // we gonna find the max value in the segment l,r then of its left or right segment we will find the until we can do so that 
    //sparse table RMQ
    cin>>n;
    foo(i,1,n+1){
        cin>>h[i];
    }
     build_rmq();

     pll ans=solve(1,n);

     cout << ans.second << "\n";


     
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
