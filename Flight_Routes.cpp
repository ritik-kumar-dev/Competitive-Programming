// JOSH TYPE //
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
    // we gonna use modfied dijistra here
    int n,m,k;
    cin>>n>>m>>k;

    vector<vpll> grp(n+1);
    foo(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        grp[a].pb({b,c});
    }

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vector<priority_queue<int>> dis(n+1);
    
    pq.push({0,1});
    dis[1].push(0); // Fixed: pq uses push(), not pb()

    while(!pq.empty()){
        auto [d,node]=pq.top();
        pq.pop();

        if(dis[node].size()==k && dis[node].top()<d) continue;

        for(auto child:grp[node]){
            int realchild=child.ff;
            int distance=child.ss;
            int new_d = d + distance; // Calculate new distance here

            // Fixed: Use .size() to check capacity, and use realchild instead of child
            if(dis[realchild].size() < k){
                pq.push({new_d, realchild});
                dis[realchild].push(new_d);
            } 
            else if(dis[realchild].size() == k) {
                if(dis[realchild].top() > new_d){
                    pq.push({new_d, realchild});
                    dis[realchild].pop();
                    dis[realchild].push(new_d);
                }
            }
        }
    }

    // Fixed: Moved the printing logic outside the while loop
    vector<int> ans;
    while(!dis[n].empty()){ 
         ans.pb(dis[n].top());
         dis[n].pop();
    }

    reverse(ans.begin(),ans.end());

    foo(i,0,k){
        ct<<ans[i]<<" ";
    }
    ct<<ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}