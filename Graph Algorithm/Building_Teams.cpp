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

vector<vi> grp;
vi vis;
vi colour;

bool dfs(int node, int col) {
    vis[node] = 1;
    colour[node] = col;

    for (auto child : grp[node]) {
        if (!vis[child]) {
            // Flip color: if col is 1, next is 2 (3-1). If col is 2, next is 1 (3-2).
            if (dfs(child, 3 - col) == false) {
                return false;
            }
        } 
        else if (colour[child] == colour[node]) {
            return false;
        }
    }
    return true;
}

void soln() {
    int n, m;
    cin >> n >> m;
    
    // Initialize global vectors for the current test case
    grp.assign(n + 1, vi());
    vis.assign(n + 1, 0);
    colour.assign(n + 1, 0);
    
    // Read edges
    foo(i, 0, m) {
        int u, v;
        cin >> u >> v;
        grp[u].pb(v);
        grp[v].pb(u);
    }
    
    // Check all components of the graph
    foo(i, 1, n + 1) {
        if (!vis[i]) {
            if (!dfs(i, 1)) {
                ct << "IMPOSSIBLE" << ed;
                return;
            }
        }
    }
    
    // If we reach here, it's possible. Print the colors.
    foo(i, 1, n + 1) {
        ct << colour[i] << " ";
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