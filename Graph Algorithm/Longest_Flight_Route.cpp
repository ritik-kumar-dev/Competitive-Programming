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

const int INF=1e18;
void soln() {  
     // Its a DAG directed acyclic graph
     // we can go with the khan's algorithm here
     int n,m;
     cin>>n>>m;
     vector<vi> grp(n+1);
     vector<int> id(n+1,0);
     vector<int> par(n+1,-1);

     foo(i,0,m){
        int u,v;
        cin>>u>>v;
        grp[u].pb(v);
        id[v]++;
     }

     queue<int> q;
     vector<int> top;
     foo(i,1,n+1){
        if(id[i]==0){
            q.push(i);
            top.pb(i);
        }
     }

     while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto child:grp[node]){
            id[child]--;
            if(id[child]==0){
                q.push(child);
                top.pb(child);
            }
        }
     }

     // all topological sorting in top 
     vector<int> dp(n+1,-INF);
     dp[1]=1;

     foo(i,0,n){
        int node=top[i];
        if(dp[node]!=-INF){
            for(auto child: grp[node]){
                if(dp[child]<dp[node]+1){
                    dp[child]=dp[node]+1;
                    par[child]=node;
                }
            }
        }
     }



     if (dp[n] == -INF) {
         cout << "IMPOSSIBLE\n";
     } else {
         cout << dp[n] << ed;
         vector<int> path;
         int curr = n;
         
         // Backtrack using the parent array
         while (curr != -1) {
             path.pb(curr);
             curr = par[curr];
         }
         
         // The path is built backwards from n to 1, so we must reverse it
         reverse(path.begin(), path.end());
         
         foo(i,0,path.size()){
             cout << path[i] << " ";
         }
         cout << ed;
     }
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