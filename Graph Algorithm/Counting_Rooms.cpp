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
char grid[1001][1001];
int vis[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int n,m;
bool good(int nx,int ny){
    if((nx<n && nx>=0) && (ny<m && ny>=0)){
        return true;
    }
    
    return false;
}

void dfs(int a,int b){
    vis[a][b]=1;

    foo(i,0,4){
        int nx=a+dx[i];
        int ny=b+dy[i];
        if(good(nx,ny) && !vis[nx][ny] && grid[nx][ny]!='#'){
            dfs(nx,ny);
        }
    }
    
}


void soln() {
   cin>>n>>m;
   foo(i,0,n){
     foo(j,0,m){
        cin>>grid[i][j];
     }
   }

   int cnt=0;
   foo(i,0,n){
     foo(j,0,m){
        if(grid[i][j]=='.' && !vis[i][j]){
            dfs(i,j);
            cnt++;
        }
     }
   }


   ct<<cnt<<ed;

     
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