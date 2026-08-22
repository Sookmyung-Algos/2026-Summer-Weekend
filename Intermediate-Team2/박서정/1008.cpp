#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> a(n, vector<int>(n));
    int sx, sy, ex, ey;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];

            if (a[i][j] == -1) {
                sx = i;
                sy = j;
                a[i][j] = 0;
            }
            else if (a[i][j] == -2) {
                ex = i;
                ey = j;
                a[i][j] = 0;
            }
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;

    dist[ex][ey] = 0;
    q.push({ ex, ey });

    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (a[nx][ny] == 0 && !(nx == sx && ny == sy) && !(nx == ex && ny == ey)) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    if (dist[sx][sy] == -1 || dist[sx][sy] > t) {
        cout << -1 << '\n';
        return 0;
    }

    const int INF = 1e9;

    vector<int> cur(n * n, INF);
    vector<int> nxt(n * n, INF);

    cur[sx * n + sy] = 0;

    int answer = INF;

    for (int time = 0; time <= t; time++) {
        int endIndex = ex * n + ey;
        answer = min(answer, cur[endIndex]);

        if (time == t) break;

        fill(nxt.begin(), nxt.end(), INF);

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                int idx = x * n + y;

                if (cur[idx] == INF) continue;
                if (dist[x][y] == -1) continue;
                if (time + dist[x][y] > t) continue;

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if (a[nx][ny] == 0 && !(nx == sx && ny == sy) && !(nx == ex && ny == ey)) continue;
                    if (dist[nx][ny] == -1) continue;
                    if (time + 1 + dist[nx][ny] > t) continue;

                    int nidx = nx * n + ny;
                    nxt[nidx] = min(nxt[nidx], cur[idx] + a[nx][ny]);
                }
            }
        }

        cur.swap(nxt);
    }

    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}