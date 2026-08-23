#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    vector<vector<long long>> rules(n, vector<long long>(n, 0));
    for (int i = 0; i < k; ++i) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        rules[x - 1][y - 1] = c;
    }
    
    vector<vector<long long>> dp(1 << n, vector<long long>(n, -1));
    
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = a[i];
    }
    
    long long max_satisfaction = 0;
    
    for (int mask = 1; mask < (1 << n); ++mask) {
        if (__builtin_popcount(mask) == m) {
            for (int i = 0; i < n; ++i) {
                if (dp[mask][i] != -1) {
                    max_satisfaction = max(max_satisfaction, dp[mask][i]);
                }
            }
            continue;
        }
        
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)) || dp[mask][i] == -1) continue;
            
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) {
                    int nxt_mask = mask | (1 << j);
                    dp[nxt_mask][j] = max(dp[nxt_mask][j], dp[mask][i] + a[j] + rules[i][j]);
                }
            }
        }
    }
    
    if (m == 0) max_satisfaction = 0;
    cout << max_satisfaction << "\n";
    
    return 0;
}
