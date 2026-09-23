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

struct Edge{
  int u,v;
  int w;
};

const int INF=1e18;

void soln() {
    // thought process bellman ford algo here
    // dp[i]=max dist from node 0 to i we can consider dp[1]=0
    int n,m;
    cin>>n>>m;

    vector<Edge> grp(m+1);
    foo(i,0,m){
        int u,v,w;
        cin>>grp[i].u>>grp[i].v>>grp[i].w;
    }

    vector<int> dis(n+1,-INF);
    dis[1]=0;

    // Normal Relaxation (bina infinite loops ke maximum score nikalna)
    // Ek graph mein bina cycle ke lamba se lamba path n-1 edges ka ho sakta hai
    foo(i,0,n-1){
        for(auto edges:grp){
            int u=edges.u;
            int v=edges.v;
            int w=edges.w;
            
            if(dis[u]!=-INF && dis[u]+w>dis[v]){
                dis[v]=dis[u]+w;
            }
        }
    }

    // Positive Cycle (Glitch/Infinity points) detect karna
    // Ek baar fir se sab edges check karenge (lagatar n times) taaki 
    // agar koi score infinity ho raha hai, toh woh saare connected rooms mein fail jaye

    foo(i,0,n){
        for(auto edges:grp){
            int u,v,w;
            u=edges.u;
            v=edges.v;
            w=edges.w;

            if(dis[u]!=-INF && dis[u]+w>dis[v]){
                dis[v]=INF;
            }
        }
    }

    if(dis[n]==INF){
        ct<<-1<<ed;
        return;
    }

    ct<<dis[n]<<ed;



     
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