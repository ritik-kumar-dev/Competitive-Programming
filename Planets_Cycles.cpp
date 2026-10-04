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

void soln() {
    int n;
    cin >> n;
    
    vi next_node(n + 1);
    foo(i, 1, n + 1) {
        cin >> next_node[i];
    }

    vi vis(n + 1, 0); // 0 = unvisited, 1 = visiting, 2 = processed
    vi ans(n + 1, 0);

    foo(i, 1, n + 1) {
        if (!vis[i]) {
            vi path;
            int curr = i;

            // Jab tak naya node milta rahe
            while (!vis[curr]) {
                vis[curr] = 1;
                path.pb(curr);
                curr = next_node[curr];
            }

            // Case 1: Cycle found
            if (vis[curr] == 1) {
                int cycle_start = -1;
                foo(j, 0, path.sz) {
                    if (path[j] == curr) {
                        cycle_start = j;
                        break;
                    }
                }
                
                int cycle_len = path.sz - cycle_start;
                
                // Cycle waale nodes ka answer cycle_len hoga
                foo(j, cycle_start, path.sz) {
                    ans[path[j]] = cycle_len;
                }
                
                // Cycle ke pehle waale nodes
                for (int j = cycle_start - 1; j >= 0; j--) {
                    ans[path[j]] = ans[next_node[path[j]]] + 1;
                }
            } 
            // Case 2: Hit an already processed node
            else if (vis[curr] == 2) {
                for (int j = path.sz - 1; j >= 0; j--) {
                    ans[path[j]] = ans[next_node[path[j]]] + 1;
                }
            }

            // Path ko completely processed mark kar do
            for (auto node : path) {
                vis[node] = 2;
            }
        }
    }

    // Output
    foo(i, 1, n + 1) {
        ct << ans[i] << " ";
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