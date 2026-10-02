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
    int n,m;
    cin>>n>>m;

    // Adjacency list to store the graph: {destination, price}
    vector<vpll> grp(n+1);

    foo(i,0,m){
        int u,v,d;
        cin>>u>>v>>d;
        grp[u].pb({v,d});
    }

    // Min-heap priority queue to always process the cheapest route first
    priority_queue<pll,vector<pll>,greater<pll>> q;
    
    // DP State Arrays
    vector<int> dis(n+1,INF);  // Min price to reach city
    vector<int> routes(n+1,0); // Number of min-price routes
    vector<int> min_f(n+1,INF);// Min flights on a min-price route
    vector<int> max_f(n+1,0);  // Max flights on a min-price route

    // Base cases for the starting city (Syrjälä)
    dis[1]=0;
    routes[1]=1;
    min_f[1]=0;
    max_f[1]=0;

    q.push({0,1});
    
    while(!q.empty()){
        pll node=q.top();
        int d=node.ff;
        int x=node.ss;
        q.pop();

        // Optimization: Skip if we have already found a cheaper way to this city
        if(d>dis[x])continue;

        for(auto child:grp[x]){
            int c=child.ff;
            int x2=child.ss;
            int new_cost=d+x2;

            // Case 1: We found a strictly cheaper route to city 'c'
            if(new_cost<dis[c]){
                dis[c]=new_cost;
                routes[c]=routes[x];
                min_f[c]=min_f[x]+1;
                max_f[c]=max_f[x]+1;
                q.push({dis[c],c}); // Push the new shortest distance
            }
            // Case 2: We found another route with the EXACT SAME minimum price
            else if(new_cost==dis[c]){
                routes[c]=(routes[c]+routes[x])%MOD; // Add the paths (modulo 10^9+7)
                min_f[c]=min(min_f[c],min_f[x]+1);   // Keep the smallest flight count
                max_f[c]=max(max_f[c],max_f[x]+1);   // Keep the largest flight count
                // We don't push to queue here because the minimum price hasn't improved
            }
        }
    }

    // Print the 4 required answers for Lehmälä (city n)
    ct<<dis[n]<<" "<<routes[n]<<" "<<min_f[n]<<" "<<max_f[n]<<ed;
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