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

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int mxscore=0;
int min_row=1e9;
int min_col=1e9;
int max_row=-1;
int max_col=-1;

bool good(int a,int b,int n,int m){
   if(((a<n)&&(a>=0)) && ((b<m)&&(b>=0))) return true;
   return false;
}

void dfs(int a, int b, int n, int m, vector<string>& grid, vector<vector<int>>& vis){
    vis[a][b]=1;
    mxscore++;
    min_row = min(min_row, a);
    min_col = min(min_col, b);
    max_row = max(max_row, a);
    max_col = max(max_col, b);

    for(int i=0; i<4; i++){
        int nx = a + dx[i];
        int ny = b + dy[i];

        if(good(nx, ny, n, m) && !vis[nx][ny] && grid[nx][ny] == '#'){
            dfs(nx, ny, n, m, grid, vis);
        }
    }
}

void soln() {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i]; // String input direct le sakte ho
    }

    // Dynamic Visited Array
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == '#'){
                // Globals reset for the NEW component
                mxscore = 0;
                min_row = 1e9;
                min_col = 1e9;
                max_row = -1;
                max_col = -1;

                // DFS call
                dfs(i, j, n, m, grid, vis);


            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        soln();
    }
    return 0;
}