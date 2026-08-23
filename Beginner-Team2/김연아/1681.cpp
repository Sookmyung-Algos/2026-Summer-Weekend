#include <iostream>
using namespace std;

const int INF = 1e9;
int N;
int cost[15][15];
int dp[1 << 13][13];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];

    int FULL = (1 << N);
    for (int mask = 0; mask < FULL; mask++)
        for (int i = 0; i < N; i++)
            dp[mask][i] = INF;

    dp[1][0] = 0; // 회사(0번)에서 시작

    for (int mask = 1; mask < FULL; mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask & (1 << u))) continue;
            if (dp[mask][u] == INF) continue;
            for (int v = 0; v < N; v++) {
                if (mask & (1 << v)) continue;
                if (cost[u][v] == 0) continue;
                int nextMask = mask | (1 << v);
                dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    int ans = INF;
    for (int u = 1; u < N; u++) {
        if (cost[u][0] == 0) continue;
        ans = min(ans, dp[FULL - 1][u] + cost[u][0]);
    }

    cout << ans << "\n";
    return 0;
}
