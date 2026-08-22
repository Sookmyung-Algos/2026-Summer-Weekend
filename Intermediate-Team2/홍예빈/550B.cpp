// Weekend - 코드포스 550B : Preparing Olympiad
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l, r;
    int x;

    cin >> n >> l >> r >> x;

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    int answer = 0;

    // 모든 부분집합 확인
    for (int mask = 0; mask < (1 << n); mask++) {
        int count = 0;
        long long sum = 0;
        int minDifficulty = INT_MAX;
        int maxDifficulty = INT_MIN;

        for (int i = 0; i < n; i++) {
            // i번째 문제를 선택한 경우
            if (mask & (1 << i)) {
                count++;
                sum += c[i];

                minDifficulty = min(minDifficulty, c[i]);
                maxDifficulty = max(maxDifficulty, c[i]);
            }
        }

        if (count >= 2 &&
            l <= sum && sum <= r &&
            maxDifficulty - minDifficulty >= x) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
