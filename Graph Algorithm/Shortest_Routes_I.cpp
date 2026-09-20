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

const int INF= 1e18;

void soln() {
    int n,m;
    cin>>n>>m;

    //BFS is only used to find the shoertest dist in the unweighted graph but now we have to use dijkstra.
    // its one way flight so its a diretced grpah
    vector<vector<pll>> grp(n+1);
    foo(i,0,m){
        int x,y,z;
        cin>>x>>y>>z;
        grp[x].pb({y,z}); // x->y 
    }

    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,1});
    vector<int> dis(n+1,INF);
    dis[1]=0;
    while(!q.empty()){
        int curr_dis=q.top().ff;
        int node=q.top().ss;
        q.pop();

        // main condition ki suppose curr dis abhi already cal dis se bda h then skip it
        if(curr_dis>dis[node]) continue;

        // now traverse through its child
        for(auto child:grp[node]){
            int node2=child.ff;
            int dist=child.ss;

            if(dis[node]+dist<dis[node2]){
                dis[node2]=dis[node]+dist;
                q.push({dis[node2],node2});
            }
        }
    }

    foo(i,1,n+1){
        cout<<dis[i]<<" ";
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