#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int MAX = 100000;

    long long cnt[MAX + 1] = {};

    // 숫자별 등장 횟수
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    long long dp[MAX + 1] = {};

    dp[0] = 0;
    dp[1] = cnt[1];

    for (int i = 2; i <= MAX; i++) {

        // i를 선택하지 않는 경우
        long long skip = dp[i - 1];

        // i를 선택하는 경우
        long long take = dp[i - 2] + i * cnt[i];

        dp[i] = max(skip, take);
    }

    cout << dp[MAX];

    return 0;
}