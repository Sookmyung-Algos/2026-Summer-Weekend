#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    long long add[18][18] = {};
 
    for(int i = 0; i < k; i++) {
        int x, y;
        long long c;
        cin >> x >> y >> c;
        x--;
        y--;
        add[x][y] = c;
    }
 
    int sz = 1 << n;
 
    vector<vector<long long>> dp(sz, vector<long long>(n, -1));
 
    for(int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }
 
    long long ans = 0;
 
    for(int mask = 1; mask < sz; mask++) {
        int cnt = __builtin_popcount(mask);
 
        for(int now = 0; now < n; now++) {
            if(dp[mask][now] == -1) continue;
 
            if(cnt == m) {
                ans = max(ans, dp[mask][now]);
                continue;
            }
 
            for(int next = 0; next < n; next++) {
                if(mask & (1 << next)) continue;
 
                int nextMask = mask | (1 << next);
 
                dp[nextMask][next] = max(
                    dp[nextMask][next],
                    dp[mask][now] + a[next] + add[now][next]
                );
            }
        }
    }
 
    cout << ans;
}
