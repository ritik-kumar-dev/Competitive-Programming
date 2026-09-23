// JOSH TYPE//
// Submission by Ritik Jaat //
#include <bits/stdc++.h>
#define ll            long long 
#define pb            push_back
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define ed            "\n"
#define ct            cout
#define int           long long
using namespace std;

struct Edge{
    int u, v, w;
};

void soln() {
    int n, m;
    cin >> n >> m;
    
    // FIX 1: Size m instead of m+1 to avoid an empty 0-weight edge
    vector<Edge> edges(m);
    foo(i, 0, m){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // FIX 2: Initialize all to 0 so we can find disconnected negative cycles
    vector<int> dis(n + 1, 0); 
    vector<int> par(n + 1, -1);
    
    int trigger = -1;

    // FIX 3 & 4: Run exactly n times. 
    // If an update happens on the last (n-th) iteration, trigger will be captured.
    foo(i, 0, n) {
        trigger = -1;
        for (auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;

            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                par[v] = u;     // Moved INSIDE the if condition
                trigger = v;   // Always record the last updated node
            }
        }
    }

    if (trigger == -1) {
        ct << "NO" << ed;
        return;
    }

    // Pigeonhole principle: backtrack n times to ensure we are deeply inside the cycle
    foo(i, 0, n) {
        trigger = par[trigger];
    }

    // FIX 5: Reconstruct the cycle properly
    vector<int> ans;
    int start_node = trigger;
    
    while(true){
        ans.pb(trigger);
        trigger = par[trigger];
        if(trigger == start_node) break; // Stop when we complete the loop
    }
    ans.pb(start_node); // Add the start node one last time to close the cycle

    reverse(ans.begin(), ans.end());

    ct << "YES" << ed;
    for (int i = 0; i < ans.size(); i++) {
        ct << ans[i] << " ";
    }
    ct << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}