#include <iostream>
using namespace std;

int N;
int cost[15][15];
bool visited[15];
int answer = 999999999;

void dfs(int now, int cnt, int sum) {

    // 이미 현재 최소 비용보다 크면 더 볼 필요 없음
    if (sum >= answer)
        return;

    if (cnt == N) {
        if (cost[now][0] != 0) {
            sum += cost[now][0];

            if (sum < answer)
                answer = sum;
        }
        return;
    }

    for (int i = 1; i < N; i++) {

        if (visited[i])
            continue;

        if (cost[now][i] == 0)
            continue;

        visited[i] = true;

        dfs(i, cnt + 1, sum + cost[now][i]);

        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost[i][j];
        }
    }

    visited[0] = true;
    dfs(0, 1, 0);

    cout << answer;

    return 0;
}