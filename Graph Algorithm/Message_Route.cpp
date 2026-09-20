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
    int n,m;
    cin>>n>>m;

    vector<vector<int>> grp(n+1);

    foo(i,0,m){
        int u,v;
        cin>>u>>v;

        grp[u].pb(v);
        grp[v].pb(u);
    }

    queue<int> q;
    int vis[n+1]={0};
    int par[n+1]={0};
    vis[1]=1;
    par[1]=-1;

    q.push(1);

    while(!q.empty()){
        int node=q.front();
        if(node==n){
            break;
        }
        
        q.pop();

        for(auto child:grp[node]){
            if(!vis[child]){
                vis[child]=1;
                par[child]=node;
                q.push(child);
            }
        }
    }

    if(!vis[n]){
        ct<<"IMPOSSIBLE"<<ed;
        return;
    }

    int cnt=n;
    vector<int> ans;
    while(cnt!=-1){
       ans.pb(cnt);
       cnt=par[cnt];
    }

    reverse(ans.begin(),ans.end());
    ct<<ans.size()<<ed;
    foo(i,0,ans.size()){
        ct<<ans[i]<<" ";
    }
    ct<<ed;

     
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