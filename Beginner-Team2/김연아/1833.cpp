#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int N, M, K;

int solve() {
    if (K == 0 || K == N * M) return 0;

    // K가 절반보다 크면 빈칸을 칠하는 것으로 변환 (경계선 길이는 동일)
    int target = min(K, N * M - K);
    int min_perimeter = INT_MAX;

    // r x c 바운딩 박스를 탐색
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (r * c < target) continue;

            // r x c 영역 안에 target개의 칸을 배치할 때의 최소 경계선 계산
            // 1. 완전히 꽉 찬 직사각형인 경우
            if (r * c == target) {
                int p = 0;
                if (r < N) p += c;
                if (c < M) p += r;
                min_perimeter = min(min_perimeter, p);
            }

            // 2. 직사각형 (r-1) x c 또는 r x (c-1) 형태에 꼬리가 붙는 형태
            // (r-1)*c + rem = target (1 <= rem < c)
            if (r > 1 && (r - 1) * c < target && target < r * c) {
                int rem = target - (r - 1) * c;
                int p = 0;
                // 기본 (r-1) x c 경계선
                if (r - 1 < N) p += c;
                if (c < M) p += (r - 1);

                // rem 개를 추가함으로써 생기는 추가 경계선
                // rem 개를 한 줄에 붙이면: 가로 변 0개 추가(기존 변 이동), 세로 변 1개(끝단) 또는 격자 경계에 따라 처리
                int add = (r < N ? 0 : -rem) + (c < M ? 1 : 0); // 정밀 계산
            }
        }
    }

    // DP를 이용한 가장 안전한 최소 둘레 계산
    // 구석(0,0)을 포함하는 연결 컴포넌트로 만들 때의 최소 경계선
    // dp[i][j][cnt]: i번째 행까지 고려했고, 직전 행에 j개의 칸을 칠했으며, 총 cnt개의 칸을 칠했을 때의 최소 경계선
    // N, M <= 30
    // 단순 기하학적 최소 둘레 계산식:
    // r x c 박스 안에 K개를 넣을 때 최소 경계는 대개 아래와 같이 결정됩니다.
    int ans = INT_MAX;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= M; c++) {
            if (r * c < target) continue;

            int base_r = (target + c - 1) / c; // 필요한 최소 행 수
            if (base_r > r) continue;

            int rem = target % c;
            int cost = 0;

            // 아래쪽 경계선
            if (base_r < N) {
                cost += (rem == 0 ? c : rem);
                if (rem != 0 && base_r - 1 < N) {
                    // 층이 나뉘는 부분
                    cost += 0; // 이미 윗단에서 계산되거나 보정
                }
            }
            // 오른쪽 경계선
            if (c < M) {
                cost += base_r;
            }

            // 보다 명확하게: r x c 안에 target개 채울 때 독립된 변의 수
            // 가로로 맞닿는 내부 변 + 세로로 맞닿는 내부 변
            // ...
        }
    }

    return min_perimeter;
}

// 정확한 DP 구현
int dp[35][35][905]; // 행, 이전 행 너비, 총 칠한 칸 수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    if (k == 0 || k == n * m) {
        cout << 0 << "\n";
        return 0;
    }

    int target = min(k, n * m - k);
    int ans = INT_MAX;

    // 바운딩 박스 (h, w) 탐색:
    // h x w 격자 안에 target개의 칸을 구석에 몰아넣을 때:
    // target = a * b + rem 형태로 만들면
    // 경계선 = (a < n ? b : 0) + (b < m ? a : 0) + (rem > 0 ? (rem의 외곽 변) : 0)

    for (int h = 1; h <= n; h++) {
        for (int w = 1; w <= m; w++) {
            if (h * w < target) continue;

            // h x w 상자 안에서 target개를 배치하는 가장 컴팩트한 형태
            // 1) h x (target/h) + 나머지
            int full_w = target / h;
            int rem = target % h;

            int p = 0;
            if (full_w > 0) {
                if (h < n) p += full_w;
                if (full_w < m) p += h;
            }
            if (rem > 0) {
                if (h < n) p += 1; // 가로 경계 1 증가
                if (full_w + 1 < m) p += rem; // 세로 경계
                else if (full_w < m) p += rem - h;
            }
            // 단, w x (target/w) 형태도 고려
            // ...
        }
    }

    // 예시: 6 6 5 -> 5 (2x2 + 1개 형태 => 가로 2+1=3, 세로 2 => 5)
    // 수학적 최적화:
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            if (a * b == target) {
                int cost = (a < n ? b : 0) + (b < m ? a : 0);
                ans = min(ans, cost);
            }
            else if (a * b > target) {
                // a * (b - 1) < target < a * b
                // a * (b - 1) 사각형에 rem 개(1 <= rem < a)를 추가
                int rem = target - a * (b - 1);
                if (rem > 0 && rem < a) {
                    int cost = (a < n ? (b - 1) : 0) + ((b - 1) < m ? a : 0);
                    // rem 개를 붙일 때:
                    // 오른쪽으로 붙이면: 세로변 rem만큼 추가, 위쪽 가로변 1 추가, 기존 가로변 일부 이동
                    int add = 0;
                    if (b < m) add += rem;
                    if (rem < a && a <= n) add += 1; // 꺾이는 부분
                    cost = (a < n ? (b - 1) : 0) + (b < m ? (a - rem) : 0) + (b < m ? rem : 0);
                    // ...
                }
            }
        }
    }

    // 직관적인 완탐: 구석에 붙는 모든 유효한 (w1 >= w2 >= ... >= wh) 모양 중 최소 둘레
    // target <= 450 이므로 O(N * M * K) DP
    const int INF = 1e9;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int c = 0; c <= target; c++)
                dp[i][j][c] = INF;

    dp[0][m][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int prev_w = 0; prev_w <= m; prev_w++) {
            for (int c = 0; c <= target; c++) {
                if (dp[i][prev_w][c] == INF) continue;

                for (int cur_w = 0; cur_w <= prev_w; cur_w++) {
                    if (c + cur_w > target) continue;

                    // 새로 생기는 경계선:
                    // 1. 아래쪽 가로 경계: cur_w (만약 마지막 행이면 i+1==n 이므로 아래쪽 경계는 0)
                    //    하지만 DP에서는 각 행의 (prev_w - cur_w) 부분을 위쪽 행의 아래 경계로 계산
                    int extra = 0;
                    // 이전 행에서 현재 행보다 튀어나온 부분의 아래쪽 노출면
                    if (i > 0) extra += (prev_w - cur_w);
                    // 현재 행의 오른쪽 수직 노출면
                    if (cur_w > 0 && cur_w < m) extra += 1;

                    dp[i + 1][cur_w][c + cur_w] = min(dp[i + 1][cur_w][c + cur_w], dp[i][prev_w][c] + extra);
                }
            }
        }
    }

    for (int prev_w = 0; prev_w <= m; prev_w++) {
        // 마지막으로 칠해진 행의 아래쪽 변 노출면 더하기
        int extra = (n < n ? prev_w : prev_w); // i=n이 아니면 prev_w만큼 노출
        // 모든 행을 다 돌았을 때의 최소값
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= m; w++) {
                if (dp[i][w][target] != INF) {
                    int total = dp[i][w][target];
                    if (i < n) total += w; // 마지막 행의 아래쪽 경계선
                    ans = min(ans, total);
                }
            }
        }
    }

    cout << (ans == INT_MAX ? 0 : ans) << "\n";

    return 0;
}