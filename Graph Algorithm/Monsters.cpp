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

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
char moves[4]={'U','D','L','R'};
void soln() {
    int n,m;
    cin>>n>>m;

    char grid[n+1][m+1];
    foo(i,0,n){
        foo(j,0,m){
            cin>>grid[i][j];
        }
    }

    // bfs for calc min time any monster can reach a grid cell
    queue<pll> q;
    vector<vector<int>> vis(n+1, vector<int>(m+1, 0));
    vector<vector<int>> min_dis(n+1,vector<int>(m+1,10000001));
    foo(i,0,n){
        foo(j,0,m){
            if(grid[i][j]=='M'){
                vis[i][j]=1;
                min_dis[i][j]=0;
                q.push({i,j});
            }
        }
    }

    while(!q.empty()){
        pll curr=q.front();
        q.pop();

        foo(i,0,4){
            int x=curr.ff+dx[i];
            int y=curr.ss+dy[i];
            if(((x>=0 &&x<n)&&(y>=0 && y<m)) && !vis[x][y] && grid[x][y]!='#'){
                vis[x][y]=1; // CAPTAIN: I had to add this line so your queue doesn't explode!
                min_dis[x][y]=min(min_dis[x][y],min_dis[curr.ff][curr.ss]+1);
                q.push({x,y});
            }

        }

    }

    vector<vector<int>> distA(n, vector<int>(m, 0));
    vector<vector<int>> parentX(n, vector<int>(m, -1));
    vector<vector<int>> parentY(n, vector<int>(m, -1));
    vector<vector<char>> step(n, vector<char>(m, ' '));
    
    int startX = -1, startY = -1;

    foo(i,0,n){
        foo(j,0,m){
            vis[i][j]=0;
            if(grid[i][j]=='A'){
                startX = i;
                startY = j;
                vis[i][j]=1; // Mark A as visited
                q.push({i,j});
            }
        }
    }

    int escapeX = -1, escapeY = -1;

    while(!q.empty()){
        pll curr=q.front();
        q.pop();
        
        // WIN CONDITION: Did we hit a boundary?
        if(curr.ff == 0 || curr.ff == n-1 || curr.ss == 0 || curr.ss == m-1) {
            escapeX = curr.ff;
            escapeY = curr.ss;
            break; // Stop! We found an exit.
        }

        foo(i,0,4){
            int x=curr.ff+dx[i];
            int y=curr.ss+dy[i];
            
            // Boundary and Wall Checks
            if(((x>=0 &&x<n)&&(y>=0 && y<m)) && !vis[x][y] && grid[x][y]!='#'){
                
                // SURVIVAL CHECK: Are we strictly faster than the monsters?
                if(distA[curr.ff][curr.ss] + 1 < min_dis[x][y]) {
                    
                    vis[x][y] = 1;
                    distA[x][y] = distA[curr.ff][curr.ss] + 1;
                    
                    parentX[x][y] = curr.ff;
                    parentY[x][y] = curr.ss;
                    step[x][y] = moves[i];
                    
                    q.push({x,y});
                }
            }
        }
    }

    // --- BACKTRACKING ---
    if (escapeX != -1) {
        cout << "YES\n";
        string path = "";
        
        int currX = escapeX;
        int currY = escapeY;
        
        // Traverse backwards from the exit to 'A'
        while (currX != startX || currY != startY) {
            path += step[currX][currY];
            int prevX = parentX[currX][currY];
            int prevY = parentY[currX][currY];
            currX = prevX;
            currY = prevY;
        }
        
        // The string is built backwards (Exit -> A), so we reverse it
        reverse(path.begin(), path.end());
        
        cout << path.size() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    soln();
    return 0;
}