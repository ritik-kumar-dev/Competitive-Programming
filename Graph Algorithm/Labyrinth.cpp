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
pair<int,int> par[1001][1001];
int vis[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
char dir[4]={'D','U','L','R'};
char step_dir[1001][1001];
int n,m;

bool good(int nx,int ny){
    if((nx<n && nx>=0) && (ny<m && ny>=0)){
        return true;
    }
    
    return false;
}

void soln() {
   cin>>n>>m;
   int sx,sy;
   int ex,ey;
   foo(i,0,n){
     foo(j,0,m){
        cin>>grid[i][j];
        if(grid[i][j]=='A'){
            sx=i;
            sy=j;
        } else if(grid[i][j]=='B'){
            ex=i;
            ey=j;
        }
     }
   }

   // for the shortest path we need the BFS 
   queue<pair<int,int>> q;
   int cnt=0;
   q.push({sx,sy});
   vis[sx][sy]=1;
   par[sx][sy]={-1,-1};

   while(!q.empty()){
      int curr_x=q.front().ff;
      int curr_y=q.front().ss;

      if(grid[curr_x][curr_y]=='B'){
         break;
      }
      q.pop();
      
      foo(i,0,4){
        int nx=curr_x+dx[i];
        int ny=curr_y+dy[i];

        if(good(nx,ny) && !vis[nx][ny] && grid[nx][ny]!='#'){
            vis[nx][ny]=1;
            par[nx][ny]={curr_x,curr_y};
            step_dir[nx][ny] = dir[i];
            q.push({nx,ny});
            cnt++;
        }

      }

   }

   // Path Reconstruction Phase
    if (!vis[ex][ey]) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    string path = "";
    pair<int, int> curr = {ex, ey};

    // Trace back from B to A
    while (curr.ff != sx || curr.ss != sy) {
        path += step_dir[curr.ff][curr.ss];
        curr = par[curr.ff][curr.ss]; // Move to parent
    }

    // Because we traced backwards from B to A, we must reverse the path
    reverse(path.begin(), path.end());

    cout << path.length() << "\n";
    cout << path << "\n";


     
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