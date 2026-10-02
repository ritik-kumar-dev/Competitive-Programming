// JOSH TYPE//
// Submission by Ritik Jaat //
// Algorithm: Edmonds-Karp for Maximum Flow
/*
========================================================================
ALGORITHM: Edmonds-Karp (Maximum Flow)
========================================================================
Concept: Hamein Source (Node 1) se Sink (Node N) tak maximum data 
bhejna hai bina kisi pipe ki limit (capacity) ko cross kiye.

Steps:
1. Shuru mein Total Flow = 0 man lo.
2. BFS ka use karke Source se Sink tak ka koi bhi ek rasta dhundo 
   jismein flow bhejne ki capacity bachi ho (capacity > 0).
3. Agar rasta mil jaye:
   a. Bottleneck nikalo: Us raste mein sabse kam capacity wali pipe 
      dhundo. Ye us raste ki max limit hogi.
   b. Us bottleneck ko apne Total Flow mein add kar do.
   c. Graph Update karo (Sabse important step):
      - Raste ki sabhi Forward pipes ki capacity se bottleneck minus kardo.
      - Raste ki sabhi Reverse pipes (Virtual Undo button) mein bottleneck 
        plus kardo.
4. Step 2 par wapas jao. Ye tab tak chalega jab tak BFS ko koi rasta
   milna band na ho jaye.
5. End mein jo Total Flow aaya, wahi final answer hai!
========================================================================
*/
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

// grp: Adjacency list graph structure ko store karne ke liye
vector<vector<int>> grp(505);
// cap: 2D array jo har pipe ki current available capacity track karega
int cap[505][505]={0};

// BFS function: Server (1) se PC (n) tak ek aisa rasta dhundhta hai jismein capacity bachi ho
bool bfs(int node, int n, vector<int> &par) {
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while(!q.empty()) {
        int node1 = q.front();
        q.pop();
        
        for(auto child : grp[node1]) {
            // Agar padosi visit nahi hua hai AUR us pipe mein flow bhejne ki capacity bachi hai
            if(!vis[child] && cap[node1][child]) {
                vis[child] = true;
                par[child] = node1; // Rasta track karne ke liye parent save kiya

                // Agar destination (Aapka PC) mil gaya, toh rasta mil gaya (true)
                if(child == n) return true;

                q.push(child);
            }
        }
    }
    // Queue khali ho gayi par rasta nahi mila
    return false;
}

void soln() {
    int n, m;
    cin >> n >> m;

    foo(i, 0, m) {
        int a, b, c;
        cin >> a >> b >> c;
        
        grp[a].pb(b); // Forward Edge (Asli pipe)
        grp[b].pb(a); // Reverse Edge (Virtual Undo pipe)
        
        // += lagaya kyunki 2 same nodes ke beech ek se zyada pipes bhi ho sakti hain
        cap[a][b] += c; 
    }

    // Parent array path track karne ke kaam aayega
    vector<int> par(n + 1, -1);
    par[1] = -2;
    int speed = 0; // Total Max Flow

    // Jab tak BFS ko Source(1) se Destination(n) tak naya rasta milta rahega
    while(bfs(1, n, par)) {
        
        // STEP 1: Raste ka Bottleneck (Minimum Capacity) nikalo
        int bottleneck = 1e18; // Shuru mein Infinity
        int curr = n;
        
        // Destination se wapas Source tak jaate hue sabse patli pipe dhundo
        while(curr != 1) {
            int back = par[curr];
            bottleneck = min(bottleneck, cap[back][curr]);
            curr = back;
        }

        // STEP 2: Graph ki Capacities Update karo
        curr = n;
        while(curr != 1) {
            int p = par[curr];
            
            // Forward Edge se capacity minus karo (Kyunki pipe itni bhar chuki hai)
            cap[p][curr] -= bottleneck;
            
            // Reverse Edge mein capacity plus karo (Undo setup ke liye)
            cap[curr][p] += bottleneck;

            curr = p;
        }

        // STEP 3: Jo bottleneck mila usko total speed mein add kar do
        speed += bottleneck;
    }

    ct << speed << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}