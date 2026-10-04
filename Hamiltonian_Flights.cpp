#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // adj[i] mein hum un cities ko store karenge jahan se city 'i' ke liye flight aati hai
    // (Reverse edges store kar rahe hain taaki DP mein pichli state dhundhne mein aasaani ho)
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // 0-based indexing ke liye (Cities 0 se n-1 tak)
        adj[v].push_back(u);
    }

    // dp[mask][i] ka 2D array
    // Total masks honge 2^n (jisko 1 << n likhte hain)
    vector<vector<int>> dp(1 << n, vector<int>(n, 0));

    // Base Case: Start at city 0 with only city 0 visited.
    // 1 << 0 ka matlab binary mein '1' hai (yaani sirf 0th bit set hai)
    dp[1][0] = 1;

    // Outer loop: Har possible checklist (mask) ke liye
    for (int mask = 2; mask < (1 << n); mask++) {
        
        // Optimization 1: Agar is mask mein Start City (City 0) visited hi nahi hai,
        // toh is raaste ka koi matlab nahi, isko skip kar do.
        if ((mask & (1 << 0)) == 0) continue;

        // Optimization 2: Humein Last City (City n-1) par sabse aakhir mein hi aana hai.
        // Agar mask mein Last City visited dikh rahi hai lekin baaki saari cities visited nahi hain 
        // (yaani mask != saare 1s), toh isko skip kar do, kyunki beech mein Last City visit nahi kar sakte.
        if ((mask & (1 << (n - 1))) && mask != ((1 << n) - 1)) continue;

        // Inner loop: Check for every city 'i' as the current ending city
        for (int i = 0; i < n; i++) {
            
            // Agar city 'i' current checklist (mask) mein visited hai tabhi aage badho
            if ((mask & (1 << i)) != 0) {
                
                // prev_mask wo checklist hai jo city 'i' visit karne se just pehle thi
                // Hum XOR (^) use karke city 'i' ka bit 0 kar dete hain
                int prev_mask = mask ^ (1 << i);
                
                // Ab un saari cities(prev_node) ko check karo jahan se 'i' tak flight aati hai
                for (int prev_node : adj[i]) {
                    
                    // Agar prev_node humari pichli checklist mein visited thi, toh raaste add kardo
                    if ((prev_mask & (1 << prev_node)) != 0) {
                        dp[mask][i] = (dp[mask][i] + dp[prev_mask][prev_node]) % MOD;
                    }
                }
            }
        }
    }

    // Final answer: Saari cities visit ho chuki hain (mask = (1 << n) - 1) 
    // aur hum last city (n - 1) par khade hain.
    cout << dp[(1 << n) - 1][n - 1] << "\n";

    return 0;
}