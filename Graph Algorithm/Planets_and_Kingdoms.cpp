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
vector<vi> revgrp(100005);
vector<int> vis(100005,0);
vector<int> visk(100005,0);
stack<int> st;
vector<int> kindom(100005);
int nking=0;
void dfs(int node){
    vis[node]=1;

    for(auto child:grp[node]){
        if(!vis[child]){
            dfs(child);
        }
    }

    st.push(node);
}

void dfs2(int node,int nking){
    visk[node]=1;
    kindom[node]=nking;

    for(auto child:revgrp[node]){
        if(!visk[child]){
            dfs2(child,nking);
        }
    }
}
void soln() {
    // its mostly the question of SCC means in scc every node can reach to another node in the component
    // Using Kosaraju's Algo we gonna find the kingdoms
    
    int n,m;
    cin>>n>>m;

    // creating graph and rev graph
    foo(i,0,m){
        int u,v;
        cin>>u>>v;
        grp[u].pb(v);
        revgrp[v].pb(u);
    }

    foo(i,1,n+1){
        if(!vis[i]){
            dfs(i);
        }
    }

    
    while(!st.empty()){
        int node=st.top();
        st.pop();
        
        if(visk[node])continue;
        else{
            visk[node]=1;
            nking++;
            dfs2(node,nking);
        }

    }


    ct<<nking<<ed;
    foo(i,1,n+1){
        ct<<kindom[i]<<" ";
    }
    ct<<ed;




     
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