#include <bits/stdc++.h>
#define ll            long long 
#define pb            push_back
#define sz            size()
#define foo(i,a,b)    for (ll i=a;i<b;i++)
#define pll           pair<ll,ll>
#define ed            "\n"
#define ct            cout
#define vpll          vector<pll>
#define int           long long
using namespace std;

// Maximum number of nodes is 10^5, max edges is 2*10^5
vector<vpll> grp(100005);
vector<int> edge_vis(200005, 0); 
vector<int> path;

// ALGORITHM STEP 3: Hierholzer's DFS
// Instead of marking nodes as visited, we mark edges as visited.
// A node is added to the path ONLY when it has no unvisited edges left (dead-end).
void dfs(int node){
    while(!grp[node].empty()){
        // Fetch the edge and remove it from the adjacency list
        auto [child, idx] = grp[node].back();
        grp[node].pop_back();
        
        // If this exact street was already crossed from the other side, skip it
        if(edge_vis[idx]) continue;

        // Mark this street as crossed
        edge_vis[idx] = 1;

        // Go deep into the next node
        dfs(child);
    }
    // When stuck (all connected edges are used), push the node to the path
    path.pb(node);
}

void soln() {
    int n, m;
    cin >> n >> m;

    vector<int> degree(n + 1, 0);
    
    // ALGORITHM STEP 1: Build the Graph
    // Since it's an undirected graph, add edges both ways but assign the SAME edge ID (i).
    foo(i, 0, m){
        int a, b;
        cin >> a >> b;
        grp[a].pb({b, i});
        grp[b].pb({a, i});
        degree[a]++;
        degree[b]++;
    }

    // ALGORITHM STEP 2: Eulerian Circuit Condition Check
    // For an undirected graph to have an Eulerian Circuit, EVERY node must have an even degree.
    foo(i, 1, n + 1){
        if(degree[i] % 2 != 0){
            ct << "IMPOSSIBLE" << ed;
            return;
        }
    }

    // Start DFS from the Post Office (Node 1)
    dfs(1);

    // ALGORITHM STEP 4: Check for Disconnected Components
    // If the graph was split into disconnected parts, the DFS wouldn't have reached all edges.
    // A valid Eulerian Circuit must contain exactly m + 1 nodes.
    if(path.sz != m + 1){
        ct << "IMPOSSIBLE" << ed;
        return;
    }

    // ALGORITHM STEP 5: Reverse the Path
    // Because we add nodes to the path at "dead-ends", the path is built backwards.
    // Reversing it gives the correct forward sequence.
    reverse(path.begin(), path.end());

    foo(i, 0, m + 1){
        ct << path[i] << " ";
    }
    ct << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}