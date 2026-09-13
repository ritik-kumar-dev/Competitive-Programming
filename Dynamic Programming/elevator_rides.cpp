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
#define vpll          vector<pll>
#define ff            first
#define ss            second
#define mod           998244353
#define MOD           1000000007
#define int           long long
using namespace std;

void soln() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    foo(i, 0, n){
        cin >> a[i]; 
    }

    // dp[mask] = {min rides, min weight of last ride}
    vector<pll> dp((1 << n), {n + 1, 0});
    dp[0] = {1, 0};

    // i is the mask here (all combinations of people)
    foo(i, 1, (1 << n)){
        foo(j, 0, n){
            // check kiya ki person j is subset (mask i) me hai ya nhi
            if(i & (1 << j)) { 
                // isme se ye person nikal kar purani state dekhi
                auto prev = dp[i ^ (1 << j)]; 
                
                pll current_option;
                // Agar previous ride me space hai
                if(prev.ss + a[j] <= x){
                    current_option = {prev.ff, prev.ss + a[j]};
                } else {
                    // Space nhi hai toh nayi ride, aur weight a[j]
                    current_option = {prev.ff + 1, a[j]};
                }
                
                dp[i] = min(dp[i], current_option);
            }
        }
    }
    
    // Final answer print karna mat bhulna (sab log hone chahiye subset me)
    cout << dp[(1 << n) - 1].ff << ed;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    soln();

    return 0;
}