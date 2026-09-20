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
#define vpll          vector<pll>
#define ff            first
#define ss            second
#define mod           998244353
#define MOD           1000000007
#define int           long long
using namespace std;

vector<vector<int>> grp(100005); // 100005 for safety against Out of Bounds
int vis[100005];
int par[100005];

// Cycle track karne ke liye global variables best hote hain
int cycle_start = -1, cycle_end = -1;

bool dfs(int node, int p){
    vis[node]=1;
    par[node]=p;

    for(auto child:grp[node]){
        if(child == p) continue; // Jis raste se aaye usko ignore karo

        if(vis[child]){ 
            // Cycle mil gayi!
            cycle_start = child;
            cycle_end = node;
            return true;
        } 
        
        if(!vis[child]){
            // Recursion ki return value ko upar bhejo
            if(dfs(child, node)) return true; 
        }
    }
    return false;
}

void soln() {
    int n,m;
    cin>>n>>m;

    foo(i,0,m){
        int u,v;
        cin>>u>>v;
        grp[u].pb(v);
        grp[v].pb(u);
    }

    foo(i,1,n+1){
        if(!vis[i]){
            if(dfs(i,-1)) break; // Pehli cycle milte hi DFS rok do
        }
    }

    if(cycle_start == -1){
        ct<<"IMPOSSIBLE"<<ed;
        return;
    }

    // Cycle Reconstruction
    vector<int> ans;
    ans.pb(cycle_start);
    
    // Cycle_end se parent k sahare wapas cycle_start tak travel karo
    int curr = cycle_end;
    while(curr != cycle_start){
        ans.pb(curr);
        curr = par[curr];
    }
    ans.pb(cycle_start); // Question ke according same city wapas add karni hai

    // Print output
    ct << ans.sz << ed;
    for(auto x : ans){
        ct << x << " ";
    }
    ct << ed;
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