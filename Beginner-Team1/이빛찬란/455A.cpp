#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    const int MAXV = 100001;
    long long cnt[MAXV] = { 0 };

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    long long dp[MAXV];
    dp[0] = 0;
    dp[1] = cnt[1] * 1;

    for (int v = 2; v < MAXV; v++) {
        long long take = dp[v - 2] + (long long)v * cnt[v];
        long long skip = dp[v - 1];
        dp[v] = max(take, skip);
    }

    cout << dp[MAXV - 1] << "\n";
    return 0;
}
