#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int board[101][101];
int dp[101][101];
int next_dp[101][101];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    int n, t;
    int sx, sy;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                sx = i;
                sy = j;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = INF;

    dp[sx][sy] = 0;

    int ans = INF;

    for (int cnt = 1; cnt <= t; cnt++) {
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                next_dp[i][j] = INF;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {

                if (dp[x][y] == INF)
                    continue;

                for (int d = 0; d < 4; d++) {

                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= n ||
                        ny < 0 || ny >= n)
                        continue;

                    if (board[nx][ny] == 0)
                        continue;

                    int cost = dp[x][y];

                    if (board[nx][ny] > 0)
                        cost += board[nx][ny];

                    next_dp[nx][ny] = min(next_dp[nx][ny], cost);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == -2) {
                    ans = min(ans, next_dp[i][j]);
                }
            }
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = next_dp[i][j];
    }

    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    return 0;
}
