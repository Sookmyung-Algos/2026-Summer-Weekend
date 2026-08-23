#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    const int INF = 1e9;

    // dp[j][k] : =현재 열 높이 j, 지금까지 칠한 칸 수 k
    vector<vector<int>> dp(N + 1, vector<int>(N * M + 1, INF));
    dp[0][0] = 0; // 0번째 가상 열, 높이 0, 칠한 칸 0

    for (int col = 1; col <= M; col++) { // duf gkskTlr wlsgod
        vector<vector<int>> ndp(N + 1, vector<int>(N * M + 1, INF));

        for (int jPrev = 0; jPrev <= N; jPrev++) {
            for (int kPrev = 0; kPrev <= N * M; kPrev++) {
                if (dp[jPrev][kPrev] == INF) continue;

                for (int j = 0; j <= N; j++) {
                    int k = kPrev + j; // j칸 칠함. 누적 칸 수 갱신
                    if (k > N * M) break;

                    int cost = abs(j - jPrev); // 이전 열과의 세로 경계선 길이
                    if (j > 0 && j < N) cost += 1; // 이번 열 안에 경계선 생기면 +1

                    int val = dp[jPrev][kPrev] + cost; 
                    if (val < ndp[j][k])
                        ndp[j][k] = val;
                }
            }
        }

        dp = ndp; // 열 하나 끝나면 dp교체
    }

    int answer = INF;
    for (int j = 0; j <= N; j++) {
        if (dp[j][K] == INF) continue;
        answer = min(answer, dp[j][K] + j); // 마지막 열과 바깥(높이0)의 경계
    }

    cout << answer << "\n";

return 0;
}