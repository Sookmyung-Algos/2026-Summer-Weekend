// CodeForce 580D. Kefa and Dishes
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

long long arr[20];
long long bonus[20][20];
long long dp[262150][20];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < k; i++)
    {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        bonus[u - 1][v - 1] = c;
    }

    int limit = 1 << n;

    for (int i = 0; i < limit; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = arr[i];
    }

    for (int mask = 0; mask < limit; mask++)
    {
        for (int last = 0; last < n; last++)
        {
            if (dp[mask][last] == -1)
            {
                continue;
            }

            for (int nxt = 0; nxt < n; nxt++)
            {
                if (!(mask & (1 << nxt)))
                {
                    int nxtMask = mask | (1 << nxt);
                    long long nxtVal = dp[mask][last] + arr[nxt] + bonus[last][nxt];

                    if (nxtVal > dp[nxtMask][nxt])
                    {
                        dp[nxtMask][nxt] = nxtVal;
                    }
                }
            }
        }
    }

    long long ans = 0;

    for (int mask = 0; mask < limit; mask++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                cnt++;
            }
        }

        if (cnt == m)
        {
            for (int last = 0; last < n; last++)
            {
                if (dp[mask][last] > ans)
                {
                    ans = dp[mask][last];
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#endif