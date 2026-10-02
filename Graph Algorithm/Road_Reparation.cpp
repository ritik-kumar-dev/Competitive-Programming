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

    vector<vpll> grp(n+1);

    foo(i,0,m){
        int u,v,x;
        cin>>u>>v>>x;
        grp[u].pb({v,x});
        grp[v].pb({u,x});
    }


    // dp[node]= min repair cost from 1 to n covering every node 
    // dp[child]=min(dp[child],dp[node]+child.w)
    // return dp[n] but it will not help bcs it will only  give me shortest path from 1 to node
    // I think minimum spanning tree will work i think soo may be prim's works here.
    // minimum spanning tree(exactly n-1 edges with no loops) prim's algo greedily we gonna move on nodes and take the shortest weight 
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,1});
    int connected_cities=0;
    int cost=0;

    vector<int> vis(n+1,0);
    while(!pq.empty()){
        auto [w,node]=pq.top();

        pq.pop();

        if(vis[node]) continue;

        vis[node]=1;
        connected_cities++;
        cost+=w;

        for(auto child: grp[node]){
            int weight=child.ss;
            int node2=child.ff;
            if(!vis[node2]) pq.push({weight,node2});
        }
    }

    if(connected_cities==n){
        ct<<cost<<ed;
        return;
    }

    ct<<"IMPOSSIBLE"<<ed;
    return;
    
     
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