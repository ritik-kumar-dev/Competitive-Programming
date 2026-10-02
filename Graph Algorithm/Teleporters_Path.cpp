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
vector<vi> grp(100005);
vector<int> path;

void dfs(int node){
    while(!grp[node].empty()){
        int child=grp[node].back();
        grp[node].pop_back();

        dfs(child);
    }

    path.pb(node);
}

void soln() {
    // Hierholzer’s Algorithm works to find an Eulerian Path using a single DFS without permanently ruining the path if you take a wrong turn.
    // Standard DFS mein hum nodes visit karte hain, par Hierholzer’s DFS mein hum edges "consume" karte hain.
    int n, m;
    cin >> n >> m;
    
    // In-degree aur Out-degree track karne ke liye arrays
    vector<int> in(n + 1, 0), out(n + 1, 0);
    
    foo(i, 0, m){
        int u, v;
        cin >> u >> v;
        grp[u].pb(v);
        out[u]++;
        in[v]++;
    }

    // 1. Eulerian Path ki Condition Check:
    // 1 se shuru ho kar 'n' par khatam hona chahiye.
    bool possible = true;
    
    // Node 1 se start hoga, isliye ek rasta bahar jyada jaana chahiye
    if (out[1] - in[1] != 1) possible = false;
    
    // Node 'n' end point hai, isliye ek rasta andar jyada aana chahiye
    if (in[n] - out[n] != 1) possible = false;
    
    // Baaki saari nodes par in-degree == out-degree honi chahiye
    for (int i = 2; i < n; i++) {
        if (in[i] != out[i]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << ed;
        return;
    }

    // 2. DFS Call
    dfs(1);
    
    // 3. Connectivity / Valid Path Check
    // Total edges 'm' the. Toh total nodes visit (path array ka size) m + 1 hona chahiye.
    // Agar chhota hai, iska matlab kuch edges disconnected the aur wahan tak path nahi pahuncha.
    if (path.sz != m + 1) {
        cout << "IMPOSSIBLE" << ed;
        return;
    }

    // 4. Print Answer in Reverse
    reverse(path.begin(), path.end());
    for (int node : path) {
        cout << node << " ";
    }
    cout << ed;
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