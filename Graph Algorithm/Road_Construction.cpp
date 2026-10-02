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

int par[100001];
int siz[100005];

int ncom,mxcom;

int find(int node){
    if(par[node]==node)return node;

    // dynamically updates the root of the component
    return par[node]=find(par[node]);
}

void unite(int node1,int node2){
    int parn1=find(node1);
    int parn2=find(node2);

    if(parn1!=parn2){
        if(siz[parn1]<siz[parn2]){
            swap(parn1,parn2);
        }
        
        par[parn2]=parn1;
        siz[parn1]+=siz[parn2];
        ncom--;
        mxcom=max(mxcom,siz[parn1]);
    }
}

void soln() {

    int n,m;
    cin>>n>>m;

    ncom=n;
    mxcom=1;

    foo(i,1,n+1){
       par[i]=i;
       siz[i]=1;
    }

    while(m--){
        int u,v;
        cin>>u>>v;
        unite(u,v);

        ct<<ncom<<" "<<mxcom<<ed;

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