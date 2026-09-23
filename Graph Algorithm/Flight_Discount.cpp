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

const int INF=1e18;

void soln() {
    int n,m;
    cin>>n>>m;

    // Fix 1: Vector of vectors for adjacency list
    vector<vpll> grp(n+1);
    foo(i,0,m){
        int u, v, c; // 'c' use kiya taaki outer 'm' shadow na ho
        cin >> u >> v >> c;
        grp[u].pb({v, c});
    }
    
    // Fix 2: Semicolon added
    vector<vector<int>> dis(n+1, vector<int>(2, INF));
    
    // Fix 3: Queue storing {distance, {node, state}}
    // Using pair<int, pair<int, int>> for this
    priority_queue<pair<int, pair<int, int>>, 
                   vector<pair<int, pair<int, int>>>, 
                   greater<pair<int, pair<int, int>>>> q;
                   
    dis[1][0]=0;
    dis[1][1]=0;
    q.push({0, {1, 0}}); // {dist=0, {node=1, state=0}}

    while(!q.empty()){
        auto top_element = q.top();
        q.pop();
        
        int d = top_element.ff;
        int u = top_element.ss.ff;
        int state = top_element.ss.ss;

        // Agar hume is node par aane ka isse better raasta pehle hi mil chuka hai, toh skip
        if(d > dis[u][state]) continue;

        for(auto child : grp[u]){
            int v = child.ff;
            int weight = child.ss;
            
            // Agar abhi tak discount use nahi kiya hai (state == 0)
            if (state == 0) {
                // Option A: Normal aage badho (bina discount ke)
                if (dis[v][0] > d + weight) {
                    dis[v][0] = d + weight;
                    q.push({dis[v][0], {v, 0}});
                }
                // YAHI PAR discount use kar lo (state becomes 1)
                if (dis[v][1] > d + weight / 2) {
                    dis[v][1] = d + weight / 2;
                    q.push({dis[v][1], {v, 1}});
                }
            } 
            // Transition 2: Agar discount pehle hi use ho chuka hai (state == 1)
            else if (state == 1) {
                // Normal aage badho (full weight dena padega)
                if (dis[v][1] > d + weight) {
                    dis[v][1] = d + weight;
                    q.push({dis[v][1], {v, 1}});
                }
            }
        }
    }
    
    // Sirf dis[n][1] print karenge kyunki humesha ek discount use karna optimal hi hoga
    cout << dis[n][1] << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}