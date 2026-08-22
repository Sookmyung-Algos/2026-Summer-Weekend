#include <iostream>
#include <vector>
#include <algorithm>

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

        x--;
        y--;

        bonus[x][y] = c;
    }

    int total = 1 << n;

    vector<vector<long long>> dp(
        total,
        vector<long long>(n, -1)
    );

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }

    long long answer = 0;

    for (int mask = 0; mask < total; mask++) {
        int cnt = __builtin_popcount(mask);

        if (cnt > m)
            continue;

        for (int last = 0; last < n; last++) {

            if (dp[mask][last] == -1)
                continue;

            if (cnt == m) {
                answer = max(answer, dp[mask][last]);
                continue;
            }

            for (int next = 0; next < n; next++) {

                if (mask & (1 << next))
                    continue;

                int nextMask = mask | (1 << next);

                dp[nextMask][next] =
                    max(
                        dp[nextMask][next],
                        dp[mask][last]
                        + a[next]
                        + bonus[last][next]
                    );
            }
        }
    }

    cout << answer;

    return 0;
}