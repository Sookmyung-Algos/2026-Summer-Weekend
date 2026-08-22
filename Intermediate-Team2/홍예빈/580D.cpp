// Weekend - 코드포스 580D : Kefa and Dishes
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> bonus(n, vector<long long>(n, 0));

    for (int i = 0; i < k; i++) {
        int x, y;
        long long c;

        cin >> x >> y >> c;
        --x;
        --y;

        bonus[x][y] = c;
    }

    int totalMasks = 1 << n;

    vector<vector<long long>> dp(
        totalMasks,
        vector<long long>(n, -1)
    );

    // 첫 번째로 먹는 요리
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    for (int mask = 1; mask < totalMasks; mask++) {
        int selectedCount = __builtin_popcount(mask);

        if (selectedCount >= m) {
            continue;
        }

        for (int last = 0; last < n; last++) {
            if (!(mask & (1 << last))) {
                continue;
            }

            if (dp[mask][last] == -1) {
                continue;
            }

            for (int next = 0; next < n; next++) {
                if (mask & (1 << next)) {
                    continue;
                }

                int nextMask = mask | (1 << next);

                dp[nextMask][next] = max(
                    dp[nextMask][next],
                    dp[mask][last]
                        + a[next]
                        + bonus[last][next]
                );
            }
        }
    }

    long long answer = 0;

    for (int mask = 0; mask < totalMasks; mask++) {
        if (__builtin_popcount(mask) != m) {
            continue;
        }

        for (int last = 0; last < n; last++) {
            answer = max(answer, dp[mask][last]);
        }
    }

    cout << answer << '\n';

    return 0;
}
