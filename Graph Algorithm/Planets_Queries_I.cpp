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

 // ye ek functional ya succesor grp h jisme har node ki out degree 1 h and bin lifting isme lgskti h na
 // dp[i][j]= des of i after 2^j steps       as k=10^9 we need log(maxK) steps to find it out

 /* 
   IMPORTANT CONCEPT: CACHE LOCALITY (Memory Optimization)
   Yahan DP table ka size dp[30][N+1] liya hai instead of dp[N+1][30].
   Kyunki jab hum DP calculate karte hain (outer loop 'j', inner loop 'i'), toh 'i' (node) lagatar badhta hai.
   Agar hum dp[N][30] rakhte, toh har iteration mein memory ki alag-alag rows par aage-peeche 
   jump karna padta (jise Cache Miss kehte hain). Ye C++ mein bahut slow hota hai aur TLE dega.
   Lekin dp[30][N+1] rakhne se hum ek hi row ke andar lagatar (contiguous) aage badhte hain, 
   bilkul waise hi jaise ek train ke dabbe mein bina bahar nikle line se saari seats check karna!
   Isse CPU ko data ekdum fast milta hai (Cache Hit) aur code ki speed 10x badh jati hai.
*/
vector<vector<int32_t>> dp(30, vector<int32_t>(n + 1));

void soln() {
    int n, q;
    cin >> n >> q;
    
    // DP dimension reverse kar diya: [30][N+1]
    // int32_t use kiya taaki long long ka overhead na aaye
    vector<vector<int32_t>> dp(30, vector<int32_t>(n + 1));
    
    foo(i, 1, n + 1) {
        int p;
        cin >> p;
        dp[0][i] = p; // 2^0 = 1 step
    }

    int max_jumps = 30;
    
    // Memory cache ke hisaab se ye order ab super fast chalega
    foo(j, 1, max_jumps) {
        foo(i, 1, n + 1) {
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
        }
    }

    while (q--) {
        int node, step;
        cin >> node >> step;
        
        for (int i = 0; i < max_jumps; i++) {
            if (step & (1LL << i)) { 
                node = dp[i][node]; // Yaha bhi dimension reverse hai
            }
        }
        
        cout << node << ed; 
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