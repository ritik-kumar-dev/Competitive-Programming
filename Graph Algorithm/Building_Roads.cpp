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

vector<vector<int>> grp(100001);
int vis[100001];
void dfs(int node){
    vis[node]=1;
    
    for(auto child:grp[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    return;
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

    vector<int> ans;

    foo(i,1,n+1){
        if(!vis[i]){
           ans.pb(i);
           dfs(i);
        }
    }

    ct<<ans.size()-1<<ed;
    foo(i,1,ans.size()){
        ct<<ans[i-1]<<" "<<ans[i]<<ed;
    }
     
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