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
 int n;
 cin>>n;
 vector<vector<char>> grid(n,vector<char>(n));
 foo(i,0,n){
    foo(j,0,n){
        cin>>grid[i][j];
    }
 }

 // we can only get either right or down dp[i][j]= lexi minimal string from 0,0 to i,j
 // dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
 // base case: dp[0][0]=a[0][0] but this approach will not gonna work bcs we can't compare string at each step neither we store the string a each state so
 // try it with the level by level BFS approach

string ans="";
ans+=grid[0][0];
vector<pll> curr_level;
curr_level.pb({0,0});

vector<vector<bool>> vis(n,vector<bool>(n,false));

int t_steps=n-1+n-1;

foo(i,0,t_steps){
    char min_char='z'+1;

    for(auto cell:curr_level){
        int i=cell.ff;
        int j=cell.ss;

        if(i+1<n) min_char=min(min_char,grid[i+1][j]);
        if(j+1<n) min_char=min(min_char,grid[i][j+1]);
    }

    ans+=min_char;
    // yha tak humne just min char dunda h but hume next level ke liye unke cordinates save krne hoge

    vector<pll> next_level;

    for(auto cell:curr_level){
        int i=cell.ff;
        int j=cell.ss;

        if(i+1<n && grid[i+1][j]==min_char && !vis[i+1][j]){
            vis[i+1][j]=true;
            next_level.pb({i+1,j});
        }
        
        if(j+1<n && grid[i][j+1]==min_char && !vis[i][j+1]){
            vis[i][j+1]=true;
            next_level.pb({i,j+1});
        }
    }

    curr_level=next_level;
}
    
cout<<ans<<ed;
     
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