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
    // if i'll use dijistra over all the nodes then the time complexity will be mlogn*n and m in worst case would be m=n^2
    // O(n^3logn) which may reach the req no of ops 

    int n,m,q;
    cin>>n>>m>>q;

    int dis[n+1][n+1];
    foo(i,1,n+1){
        foo(j,1,n+1){
            if(i==j)dis[i][j]=0;
            else dis[i][j]=INF;
        }
    }

    foo(i,0,m){
        int x,y,z;
        cin>>x>>y>>z;
         dis[x][y]=min(dis[x][y],z);
         dis[y][x]=min(dis[x][y],z);
    }

    // floyd warshal Algorithm
    foo(k,1,n+1){
        foo(i,1,n+1){
            foo(j,1,n+1){
                 dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }


    while(q--){
        int n1,n2;
        cin>>n1>>n2;
        if(dis[n1][n2]==INF){
            cout<<-1<<ed;
            continue;
        }
        cout<<dis[n1][n2]<<ed;
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