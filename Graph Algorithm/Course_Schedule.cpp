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

void soln() {
    int n,m;
    cin>>n>>m;

    vector<vi> grp(n+1);
    vector<int> in_degree(n+1,0);

    foo(i,0,m){
        int u,v;
        cin>>u>>v;
        grp[u].pb(v);
        in_degree[v]++;
    }

    queue<int> q;
    vector<int> ans;
    foo(i,1,n+1){
        if(in_degree[i]==0){
            q.push(i);
            ans.pb(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto child:grp[node]){
            in_degree[child]--;
            if(in_degree[child]==0){
                q.push(child);
                ans.pb(child);
            } 
        }
    }

    // Check if we were able to process all 'n' courses
    if(ans.size() == n) {
        foo(i,0,n){
            ct<<ans[i]<<" ";
        }
        ct<<ed;
    } else {
        // A cycle exists, impossible to complete
        ct<<"IMPOSSIBLE"<<ed;
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